# Licensed under Apache License Version 2.0 - see LICENSE

# Built-ins
from __future__ import absolute_import, division, print_function
import itertools
import operator
import pickle

# 3rd party
import pytest

# This module
import iteration_utilities

# Test helper
import helper_funcs
from helper_cls import T, toT, failingTIterator
from helper_leak import memory_leak_decorator


roundrobin = iteration_utilities.roundrobin


@memory_leak_decorator()
def test_roundrobin_empty1():
    assert list(roundrobin()) == []


@memory_leak_decorator()
def test_roundrobin_empty2():
    assert list(roundrobin([])) == []


@memory_leak_decorator()
def test_roundrobin_empty3():
    assert list(roundrobin([], (), {})) == []


@memory_leak_decorator()
def test_roundrobin_normal1():
    assert list(roundrobin([T(1)], [T(1), T(2)], [T(1), T(2), T(3)]
                           )) == toT([1, 1, 1, 2, 2, 3])


@memory_leak_decorator()
def test_roundrobin_normal2():
    assert list(roundrobin([T(1), T(2), T(3)], [T(1)], [T(1), T(2)]
                           )) == toT([1, 1, 1, 2, 2, 3])


@memory_leak_decorator()
def test_roundrobin_normal3():
    assert list(roundrobin([T(1), T(2)], [T(1), T(2), T(3)], [T(1)]
                           )) == toT([1, 1, 1, 2, 2, 3])


@memory_leak_decorator()
def test_roundrobin_normal4():
    # generator
    assert list(roundrobin((i for i in [T(1), T(2), T(3)]),
                           (i for i in [T(1)]),
                           (i for i in [T(1), T(2)]))
                ) == toT([1, 1, 1, 2, 2, 3])


@memory_leak_decorator(collect=True)
def test_roundrobin_failure1():
    with pytest.raises(TypeError):
        list(roundrobin(T(1)))


@memory_leak_decorator(collect=True)
def test_roundrobin_failure2():
    with pytest.raises(TypeError):
        list(roundrobin([T(1)], T(1)))


@memory_leak_decorator(collect=True)
def test_roundrobin_failure3():
    # Test that a failing iterator doesn't raise a SystemError
    with pytest.raises(TypeError) as exc:
        next(roundrobin(failingTIterator()))
    assert 'eq expected 2 arguments, got 1' in str(exc)


@memory_leak_decorator(collect=True)
def test_roundrobin_failure4():
    # Test that a failing iterator doesn't raise a SystemError
    with pytest.raises(TypeError) as exc:
        list(roundrobin([T(1), T(2)],
                        failingTIterator()))
    assert 'eq expected 2 arguments, got 1' in str(exc)


@memory_leak_decorator(collect=True)
def test_roundrobin_failure5():
    # Test that a failing iterator doesn't raise a SystemError
    rr = roundrobin(failingTIterator(offset=1, repeats=10),
                    [T(1), T(2), T(3), T(4)])
    assert next(rr) == T(1)
    assert next(rr) == T(1)
    with pytest.raises(TypeError) as exc:
        next(rr)
    assert 'eq expected 2 arguments, got 1' in str(exc)


@memory_leak_decorator(collect=True)
def test_roundrobin_copy1():
    helper_funcs.iterator_copy(roundrobin([T(1), T(2), T(3), T(4)]))


@memory_leak_decorator(collect=True)
def test_roundrobin_failure_setstate1():
    # setstate active < 0
    rr = roundrobin([T(1), T(2), T(3), T(4)])
    with pytest.raises(ValueError):
        rr.__setstate__((1, -1))


@memory_leak_decorator(collect=True)
def test_roundrobin_failure_setstate2():
    # setstate numactive < 0
    rr = roundrobin([T(1), T(2), T(3), T(4)])
    with pytest.raises(ValueError):
        rr.__setstate__((-1, 0))


@memory_leak_decorator(collect=True)
def test_roundrobin_failure_setstate3():
    # setstate numactive <= active
    rr = roundrobin([T(1), T(2), T(3), T(4)])
    with pytest.raises(ValueError):
        rr.__setstate__((1, 1))


@memory_leak_decorator(collect=True)
def test_roundrobin_failure_setstate4():
    # setstate numactive <= active (numactive = 0)
    rr = roundrobin()
    with pytest.raises(ValueError):
        rr.__setstate__((0, 1))


@memory_leak_decorator(collect=True)
def test_roundrobin_failure_setstate5():
    # setstate numactive > len(iteratortuple)
    rr = roundrobin([T(1), T(2), T(3), T(4)])
    with pytest.raises(ValueError):
        rr.__setstate__((2, 1))


@memory_leak_decorator(collect=True)
def test_roundrobin_failure_setstate6():
    # setstate numactive > len(iteratortuple) (after exhausting one iterable)
    rr = roundrobin([T(1)], [T(1), T(2), T(3), T(4)])
    assert [i for i in itertools.islice(rr, 3)] == toT([1, 1, 2])
    with pytest.raises(ValueError):
        rr.__setstate__((2, 1))


@memory_leak_decorator(collect=True)
def test_roundrobin_failure_setstate7():
    helper_funcs.iterator_setstate_list_fail(
            roundrobin([T(1)], [T(1), T(2), T(3), T(4)]))


@memory_leak_decorator(collect=True)
def test_roundrobin_failure_setstate8():
    helper_funcs.iterator_setstate_empty_fail(
            roundrobin([T(1)], [T(1), T(2), T(3), T(4)]))


@pytest.mark.xfail(iteration_utilities.EQ_PY2,
                   reason='pickle does not work on Python 2')
@memory_leak_decorator(offset=1)
def test_roundrobin_pickle1():
    rr = roundrobin([T(1), T(2), T(3)], [T(1), T(2), T(3)])
    assert next(rr) == T(1)
    x = pickle.dumps(rr)
    assert list(pickle.loads(x)) == toT([1, 2, 2, 3, 3])


@pytest.mark.xfail(iteration_utilities.EQ_PY2,
                   reason='pickle does not work on Python 2')
@memory_leak_decorator(offset=1)
def test_roundrobin_pickle2():
    rr2 = roundrobin([T(1)], [T(1), T(2), T(3)])
    assert next(rr2) == T(1)
    assert next(rr2) == T(1)
    assert next(rr2) == T(2)
    x = pickle.dumps(rr2)
    assert list(pickle.loads(x)) == [T(3)]


@pytest.mark.xfail(not iteration_utilities.GE_PY34,
                   reason='length does not work before Python 3.4')
@memory_leak_decorator()
def test_roundrobin_lengthhint1():
    it = roundrobin([0], [1, 2, 3], [1])
    assert operator.length_hint(it) == 5
    next(it)
    assert operator.length_hint(it) == 4
    next(it)
    assert operator.length_hint(it) == 3
    next(it)
    assert operator.length_hint(it) == 2
    next(it)
    assert operator.length_hint(it) == 1
    next(it)
    assert operator.length_hint(it) == 0
