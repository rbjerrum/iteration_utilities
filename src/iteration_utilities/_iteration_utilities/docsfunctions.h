/******************************************************************************
 * Licensed under Apache License Version 2.0 - see LICENSE
 *****************************************************************************/

#ifndef PYIU_DOCSFUNCTIONS_H
#define PYIU_DOCSFUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

#define PY_SSIZE_T_CLEAN
#include <Python.h>

PyDoc_STRVAR(PyIU_Placeholder_name, "Placeholder");
PyDoc_STRVAR(PyIU_module_name, "iteration_utilities._iteration_utilities");
PyDoc_STRVAR(PyIU_module_doc, "This is the C extension module used by iteration_utilities.");

PyDoc_STRVAR(
    PyIU_TupleToList_and_InsertItemAtIndex_doc,
    "_parse_args(tup, item, pos, /)\n"
    "--\n\n"
    "Converts the `tup` to a new `tuple` and inserts `item` at `pos`.\n"
    "\n"
    ".. warning::\n"
    "   This function is especially made for internal use, **DO NOT USE THIS \n"
    "   FUNCTION** anywhere else.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "tup : tuple\n"
    "    The tuple to convert.\n"
    "    \n"
    "    .. warning::\n"
    "       This function will encounter a segmentation fault if `tup` is not\n"
    "       a tuple.\n"
    "\n"
    "item : any type\n"
    "    The item to insert.\n"
    "\n"
    "pos : int\n"
    "    The position where to insert the `item`. \n"
    "    \n"
    "    .. warning::\n"
    "       No bounds checking - If `pos` is not carefully chosen the function \n"
    "       will segfault!\n"
    "\n"
    "Returns\n"
    "-------\n"
    "lst : tuple\n"
    "    The converted `tup` with `item` inserted.\n"
    "\n"
    "Notes\n"
    "-----\n"
    "This is equivalent to:\n"
    "\n"
    ".. code::\n"
    "\n"
    "    def _parse_args(args, item, pos):\n"
    "        return tuple(args[:pos]) + (item, ) + tuple(args[pos:])\n");

PyDoc_STRVAR(
    PyIU_RemoveFromDictWhereValueIs_doc,
    "_parse_kwargs(dct, item, /)\n"
    "--\n\n"
    "Removes every key from the `dct` where the ``dct[key] is item``.\n"
    "\n"
    ".. warning::\n"
    "   This function is especially made for internal use, **DO NOT USE THIS \n"
    "   FUNCTION** anywhere else.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "dct : dict\n"
    "    The dictionary from which to remove the keys.\n"
    "\n"
    "item : any type\n"
    "    The item to check for.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "nothing. This function works in-place.\n"
    "\n"
    "Notes\n"
    "-----\n"
    "This is equivalent to:\n"
    "\n"
    ".. code::\n"
    "\n"
    "    def _parse_kwargs(dct, item):\n"
    "        keys_to_remove = [key for key in dct if dct[key] is item]\n"
    "        for key in keys_to_remove:\n"
    "            del dct[key]\n");

PyDoc_STRVAR(
    PyIU_IsNone_doc,
    "is_None(value, /)\n"
    "--\n\n"
    "Returns ``True`` if `value` is ``None``, otherwise ``False``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "value : any type \n"
    "    The value to test for ``None``.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "is_none : :py:class:`bool`\n"
    "    ``True`` if `value` is ``None`` otherwise it returns ``False``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This function is equivalent to ``lambda x: x is None`` but significantly\n"
    "faster::\n"
    "\n"
    "    >>> from iteration_utilities import is_None\n"
    "    >>> is_None(None)\n"
    "    True\n"
    "    >>> is_None(False)\n"
    "    False\n"
    "\n"
    "This can be used for example to remove all ``None`` from an iterable::\n"
    "\n"
    "    >>> import sys\n"
    "    >>> import itertools\n"
    "    >>> filterfalse = itertools.ifilterfalse if sys.version_info.major == 2 else itertools.filterfalse\n"
    "    >>> list(filterfalse(is_None, [1, None, 3, 4, 5, None, 7]))\n"
    "    [1, 3, 4, 5, 7]\n");

PyDoc_STRVAR(
    PyIU_IsNotNone_doc,
    "is_not_None(value, /)\n"
    "--\n\n"
    "Returns ``False`` if `value` is ``None``, otherwise ``True``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "value : any type \n"
    "    The value to test for ``None``.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "is_not_none : :py:class:`bool`\n"
    "    ``False`` if `value` is ``None`` otherwise it returns ``True``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This function is equivalent to ``lambda x: x is not None`` but significantly\n"
    "faster::\n"
    "\n"
    "    >>> from iteration_utilities import is_not_None\n"
    "    >>> is_not_None(None)\n"
    "    False\n"
    "    >>> is_not_None(False)\n"
    "    True\n");

PyDoc_STRVAR(
    PyIU_IsEven_doc,
    "is_even(value, /)\n"
    "--\n\n"
    "Returns ``True`` if `value` is even, otherwise ``False``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "value : any type \n"
    "    The value to test if even.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "is_even : :py:class:`bool`\n"
    "    ``True`` if `value` is even otherwise it returns ``False``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This function is equivalent to ``lambda x: not x % 2`` but significantly\n"
    "faster::\n"
    "\n"
    "    >>> from iteration_utilities import is_even\n"
    "    >>> is_even(0)\n"
    "    True\n"
    "    >>> is_even(1)\n"
    "    False\n"
    "    >>> is_even(2)\n"
    "    True\n");

PyDoc_STRVAR(
    PyIU_IsOdd_doc,
    "is_odd(value, /)\n"
    "--\n\n"
    "Returns ``True`` if `value` is odd, otherwise ``False``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "value : any type \n"
    "    The value to test if odd.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "is_odd : :py:class:`bool`\n"
    "    ``True`` if `value` is odd otherwise it returns ``False``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This function is equivalent to ``lambda x: bool(x % 2)`` but significantly\n"
    "faster::\n"
    "\n"
    "    >>> from iteration_utilities import is_odd\n"
    "    >>> is_odd(0)\n"
    "    False\n"
    "    >>> is_odd(1)\n"
    "    True\n"
    "    >>> is_odd(2)\n"
    "    False\n");

PyDoc_STRVAR(
    PyIU_IsIterable_doc,
    "is_iterable(value, /)\n"
    "--\n\n"
    "Returns ``True`` if `value` is iterable, otherwise ``False``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "value : any type \n"
    "    The value to test if iterable.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "is_iterable : :py:class:`bool`\n"
    "    ``True`` if `value` is iterable otherwise it returns ``False``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "A few simple examples::\n"
    "\n"
    "    >>> from iteration_utilities import is_iterable\n"
    "    >>> is_iterable(0)\n"
    "    False\n"
    "    >>> is_iterable('abc')\n"
    "    True\n"
    "    >>> is_iterable([1,2,3])\n"
    "    True\n");

PyDoc_STRVAR(
    PyIU_MathSquare_doc,
    "square(value, /)\n"
    "--\n\n"
    "Returns the squared `value`.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "value : any type\n"
    "    The value to be squared. The type of the `value` must support ``pow``.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "square : any type\n"
    "    Returns ``value**2``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "It is not possible to apply :py:func:`functools.partial` to :py:func:`pow` \n"
    "so that one has a one-argument square function and is significantly faster \n"
    "than ``lambda x: x**2``::\n"
    "\n"
    "    >>> from iteration_utilities import square\n"
    "    >>> square(1)\n"
    "    1\n"
    "    >>> square(2.0)\n"
    "    4.0\n");

PyDoc_STRVAR(
    PyIU_MathDouble_doc,
    "double(value, /)\n"
    "--\n\n"
    "Returns the doubled `value`.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "value : any type\n"
    "    The value to be doubled..\n"
    "\n"
    "Returns\n"
    "-------\n"
    "doubled : any type\n"
    "    Returns ``value*2``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This function is equivalent to ``lambda x: x*2`` and for numerical arguments\n"
    "to ``functools.partial(operator.mul, 2)`` but faster::\n"
    "\n"
    "    >>> from iteration_utilities import double\n"
    "    >>> double(1)\n"
    "    2\n"
    "    >>> double(2.0)\n"
    "    4.0\n");

PyDoc_STRVAR(
    PyIU_MathReciprocal_doc,
    "reciprocal(value, /)\n"
    "--\n\n"
    "Returns ``1 / value``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "value : any type\n"
    "    The value for the computation.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "reciprocal  : any type\n"
    "    Returns ``1 / value``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This is equivalent to ``lambda x: 1 / x``\n"
    "or ``functools.partial(operator.truediv, 1)`` but faster::\n"
    "\n"
    "    >>> from iteration_utilities import reciprocal \n"
    "    >>> reciprocal(1)\n"
    "    1.0\n"
    "    >>> reciprocal(2)\n"
    "    0.5\n"
    "    >>> reciprocal(4)\n"
    "    0.25\n");

PyDoc_STRVAR(
    PyIU_MathRadd_doc,
    "radd(op1, op2, /)\n"
    "--\n\n"
    "Returns ``op2 + op1``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "op1, op2 : any type\n"
    "    The values to be added.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "radd : any type\n"
    "    Returns ``op2 + op1``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "Equivalent to ``lambda x, y: y + x``::\n"
    "\n"
    "    >>> from iteration_utilities import radd\n"
    "    >>> radd(2, 2)\n"
    "    4\n");

PyDoc_STRVAR(
    PyIU_MathRsub_doc,
    "rsub(op1, op2, /)\n"
    "--\n\n"
    "Returns ``op2 - op1``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "op1, op2 : any type\n"
    "    The values to be subtracted.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "rsub : any type\n"
    "    Returns ``op2 - op1``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "Equivalent to ``lambda x, y: y - x``::\n"
    "\n"
    "    >>> from iteration_utilities import rsub\n"
    "    >>> rsub(2, 5)\n"
    "    3\n");

PyDoc_STRVAR(
    PyIU_MathRmul_doc,
    "rmul(op1, op2, /)\n"
    "--\n\n"
    "Returns ``op2 * op1``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "op1, op2 : any type\n"
    "    The values to be multiplied.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "rmul : any type\n"
    "    Returns ``op2 * op1``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "Equivalent to ``lambda x, y: y * x``::\n"
    "\n"
    "    >>> from iteration_utilities import rmul\n"
    "    >>> rmul(2, 2)\n"
    "    4\n");

PyDoc_STRVAR(
    PyIU_MathRdiv_doc,
    "rdiv(op1, op2, /)\n"
    "--\n\n"
    "Returns ``op2 / op1``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "op1, op2 : any type\n"
    "    The values to be divided.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "rdiv : any type\n"
    "    Returns ``op2 / op1``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "Equivalent to ``lambda x, y: y / x``::\n"
    "\n"
    "    >>> from iteration_utilities import rdiv\n"
    "    >>> rdiv(10, 1)\n"
    "    0.1\n");

PyDoc_STRVAR(
    PyIU_MathRfdiv_doc,
    "rfdiv(op1, op2, /)\n"
    "--\n\n"
    "Returns ``op2 // op1``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "op1, op2 : any type\n"
    "    The values to be floor divided.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "rfdiv : any type\n"
    "    Returns ``op2 // op1``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "Equivalent to ``lambda x, y: y // x``::\n"
    "\n"
    "    >>> from iteration_utilities import rfdiv\n"
    "    >>> rfdiv(10, 22)\n"
    "    2\n");

PyDoc_STRVAR(
    PyIU_MathRpow_doc,
    "rpow(op1, op2, /)\n"
    "--\n\n"
    "Returns ``op2 ** op1``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "op1, op2 : any type\n"
    "    The values for the operation.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "rpow : any type\n"
    "    Returns ``op2 ** op1``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "Equivalent to ``lambda x, y: y ** x``::\n"
    "\n"
    "    >>> from iteration_utilities import rpow\n"
    "    >>> rpow(3, 2)\n"
    "    8\n");

PyDoc_STRVAR(
    PyIU_MathRmod_doc,
    "rmod(op1, op2, /)\n"
    "--\n\n"
    "Returns ``op2 % op1``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "op1, op2 : any type\n"
    "    Get the remainder of these two operands.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "rmod : any type\n"
    "    Returns ``op2 % op1``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "Equivalent to ``lambda x, y: y % x``::\n"
    "\n"
    "    >>> from iteration_utilities import rmod\n"
    "    >>> rmod(2, 5)\n"
    "    1\n");

PyDoc_STRVAR(
    PyIU_ReturnIdentity_doc,
    "return_identity(obj, /)\n"
    "--\n\n"
    "Always return the argument.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "obj : any type \n"
    "    The `obj` to return.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "identity : any type\n"
    "    The argument itself.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This function is equivalent to ``lambda x: x`` but significantly faster::\n"
    "\n"
    "    >>> from iteration_utilities import return_identity\n"
    "    >>> return_identity(1)\n"
    "    1\n"
    "    >>> return_identity('abc')\n"
    "    'abc'\n");

PyDoc_STRVAR(
    PyIU_ReturnCalled_doc,
    "return_called(func, /)\n"
    "--\n\n"
    "Return the result of ``func()``.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "func : callable \n"
    "    The function to be called.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "result : any type\n"
    "    The result of ``func()``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This function is equivalent to ``lambda x: x()`` but significantly\n"
    "faster::\n"
    "\n"
    "    >>> from iteration_utilities import return_called\n"
    "    >>> return_called(int)\n"
    "    0\n");

PyDoc_STRVAR(
    PyIU_ReturnFirstArg_doc,
    "return_first_arg(*args, **kwargs)\n"
    "--\n\n"
    "Always return the first positional argument given to the function.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "args, kwargs \n"
    "    any number of positional or keyword parameter.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "first_positional_argument : any type\n"
    "    Always returns the first positional argument given to the function.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This function is equivalent to ``lambda *args, **kwargs: args[0]`` but\n"
    "significantly faster::\n"
    "\n"
    "    >>> from iteration_utilities import return_first_arg\n"
    "    >>> return_first_arg(1, 2, 3, 4, a=100)\n"
    "    1\n");

PyDoc_STRVAR(
    PyIU_AllDistinct_doc,
    "all_distinct(iterable, /)\n"
    "--\n\n"
    "Checks if all items in the `iterable` are distinct.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "iterable : iterable\n"
    "    `Iterable` containing the elements.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "distinct : :py:class:`bool`\n"
    "    ``True`` if no two values are equal and ``False`` if there is at least\n"
    "    one duplicate in `iterable`.\n"
    "\n"
    "Notes\n"
    "-----\n"
    "The items in the `iterable` should implement equality.\n"
    "\n"
    "If the items are hashable the function is much faster.\n"
    "\n"
    "Examples\n"
    "--------\n"
    ">>> from iteration_utilities import all_distinct\n"
    ">>> all_distinct('AAAABBBCCDAABBB')\n"
    "False\n"
    "\n"
    ">>> all_distinct('abcd')\n"
    "True\n");

PyDoc_STRVAR(
    PyIU_AllEqual_doc,
    "all_equal(iterable, /)\n"
    "--\n\n"
    "Checks if all the elements are equal to each other.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "iterable : iterable\n"
    "    Any `iterable` to test.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "all_equal : :py:class:`bool`\n"
    "    ``True`` if all elements in `iterable` are equal or ``False`` if not.\n"
    "\n"
    "Notes\n"
    "-----\n"
    "If the input is empty the function returns ``True``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    ">>> from iteration_utilities import all_equal\n"
    ">>> all_equal([1,1,1,1,1,1,1,1,1])\n"
    "True\n"
    "\n"
    ">>> all_equal([1,1,1,1,1,1,1,2,1])\n"
    "False\n");

PyDoc_STRVAR(
    PyIU_AllIsinstance_doc,
    "all_isinstance(iterable, types)\n"
    "--\n\n"
    "Like :py:func:`isinstance` but for `iterables`.\n"
    "\n"
    "Checks if all items in `iterable` are instances of `types`.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "iterable : iterable\n"
    "    Each item of the `iterable` is tested with ``isinstance(item, types)``.\n"
    "\n"
    "types : :py:class:`type` or :py:class:`tuple` of types\n"
    "    Test for this type if it's a single class or test if the item is of any\n"
    "    of the types (if types is a :py:class:`tuple`).\n"
    "\n"
    "Returns\n"
    "-------\n"
    "all : :py:class:`bool`\n"
    "    ``True`` if all elements in `iterable` are instances of `types`,\n"
    "    ``False`` if not.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This function is equivalent (but faster) than\n"
    "``all(isinstance(item, types) for item in iterable)``::\n"
    "\n"
    "    >>> from iteration_utilities import all_isinstance\n"
    "    >>> all_isinstance(range(100), int)\n"
    "    True\n"
    "\n"
    "    >>> all_isinstance([1, 2, 3.2], (int, float))\n"
    "    True\n"
    "\n"
    ".. warning::\n"
    "    This function returns ``True`` if the `iterable` is empty.\n");

PyDoc_STRVAR(
    PyIU_Monotone_doc,
    "all_monotone(iterable, decreasing=False, strict=False)\n"
    "--\n\n"
    "Checks if the elements in `iterable` are (strictly) monotonic \n"
    "increasing or decreasing.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "iterable : iterable\n"
    "    Any `iterable` to test.\n"
    "\n"
    "decreasing : :py:class:`bool`, optional\n"
    "    If ``False`` check if the values are monotonic increasing, otherwise\n"
    "    check for monotone decreasing.\n"
    "    Default is ``False``.\n"
    "\n"
    "strict : :py:class:`bool`, optional\n"
    "    If ``True`` check if the elements are strictly greater or smaller\n"
    "    (``>`` or ``<``) than their predecessor. Otherwise use ``>=`` and ``<=``.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "monotonic : :py:class:`bool`\n"
    "    ``True`` if all elements in `iterable` are monotonic or ``False`` if not.\n"
    "\n"
    "Notes\n"
    "-----\n"
    "If the input is empty the function returns ``True``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This is roughly equivalent to\n"
    "``all(itertools.starmap(operator.lt, iteration_utilities.successive(iterable, 2)))``\n"
    "with the appropriate operator depending on `decreasing` and `strict`::\n"
    "\n"
    "    >>> from iteration_utilities import all_monotone\n"
    "    >>> all_monotone([1,1,1,1,1,1,1,1,1])\n"
    "    True\n"
    "    >>> all_monotone([1,1,1,1,1,1,1,1,1], strict=True)\n"
    "    False\n"
    "    >>> all_monotone([2,1,1,1,1,1,1,1,0], decreasing=True)\n"
    "    True\n"
    "    >>> all_monotone([2,1,1,1,1,1,1,1,0], decreasing=True, strict=True)\n"
    "    False\n");

PyDoc_STRVAR(
    PyIU_AnyIsinstance_doc,
    "any_isinstance(iterable, types)\n"
    "--\n\n"
    "Like :py:func:`isinstance` but for `iterables`.\n"
    "\n"
    "Checks if any item in `iterable` is an instance of `types`.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "iterable : iterable\n"
    "    Each item of the `iterable` is tested with ``isinstance(item, types)``.\n"
    "\n"
    "types : :py:class:`type` or :py:class:`tuple` of types\n"
    "    Test for this type if it's a single class or test if the item is of any\n"
    "    of the types (if types is a :py:class:`tuple`).\n"
    "\n"
    "Returns\n"
    "-------\n"
    "any : :py:class:`bool`\n"
    "    ``True`` if any elements in `iterable` is an instance of `types`,\n"
    "    ``False`` if not.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This function is equivalent (but faster) than\n"
    "``any(isinstance(item, types) for item in iterable)``\n"
    "\n"
    "    >>> from iteration_utilities import any_isinstance\n"
    "    >>> all_isinstance(range(100), int)\n"
    "    True\n"
    "\n"
    "    >>> any_isinstance([1, 2, 3.2], float)\n"
    "    True\n");

PyDoc_STRVAR(
    PyIU_Argmin_doc,
    "argmin(iterable, /, key, default)\n"
    "--\n\n"
    "Find index of the minimum.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "iterable : iterable\n"
    "    The `iterable` for which to calculate the index of the minimum.\n"
    "\n"
    "    .. note::\n"
    "        Instead of one `iterable` it is also possible to pass the values (at\n"
    "        least 2) as positional arguments.\n"
    "\n"
    "key : callable, optional\n"
    "    If not given then compare the values, otherwise compare ``key(item)``.\n"
    "\n"
    "default : :py:class:`int`, optional\n"
    "    If given an empty `iterable` will return `default` instead of raising a \n"
    "    ``ValueError``.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "argmin : :py:class:`int`\n"
    "    The index of the minimum or default if the `iterable` was empty.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This is equivalent (but faster) than \n"
    "``min(enumerate(iterable), key=operator.itemgetter(1))[0]``::\n"
    "\n"
    "    >>> from iteration_utilities import argmin\n"
    "    >>> argmin(3,2,1,2,3)\n"
    "    2\n"
    "\n"
    "It allows a `key` function::\n"
    "\n"
    "    >>> argmin([3, -3, 0], key=abs)\n"
    "    2\n"
    "\n"
    "And a `default`::\n"
    "\n"
    "    >>> argmin([], default=10)\n"
    "    10\n");

PyDoc_STRVAR(
    PyIU_Argmax_doc,
    "argmax(iterable, /, key=None, default=None)\n"
    "--\n\n"
    "Find index of the maximum.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "iterable : iterable\n"
    "    The `iterable` for which to calculate the index of the maximum.\n"
    "\n"
    "    .. note::\n"
    "        Instead of one `iterable` it is also possible to pass the values (at\n"
    "        least 2) as positional arguments.\n"
    "\n"
    "key : callable, optional\n"
    "    If not given then compare the values, otherwise compare ``key(item)``.\n"
    "\n"
    "default : :py:class:`int`, optional\n"
    "    If not given raise ``ValueError`` if the `iterable` is empty otherwise\n"
    "    return ``default``\n"
    "\n"
    "Returns\n"
    "-------\n"
    "argmax : :py:class:`int`\n"
    "    The index of the maximum or default if the `iterable` was empty.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This is equivalent (but faster) than \n"
    "``max(enumerate(iterable), key=operator.itemgetter(1))[0]``::\n"
    "\n"
    "    >>> from iteration_utilities import argmax\n"
    "    >>> argmax(3,2,1,2,3)\n"
    "    0\n"
    "\n"
    "It allows a `key` function::\n"
    "\n"
    "    >>> argmax([0, -3, 3, 0], key=abs)\n"
    "    1\n"
    "\n"
    "And a `default`::\n"
    "\n"
    "    >>> argmax([], default=10)\n"
    "    10\n");

PyDoc_STRVAR(
    PyIU_Count_doc,
    "count_items(iterable, pred=None, eq=False)\n"
    "--\n\n"
    "Count how many times the predicate is true.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "iterable : iterable\n"
    "    Any `iterable` to count in.\n"
    "\n"
    "pred : callable, any type, None, optional\n"
    "    Predicate to test. Depending on the `eq` parameter this parameter has\n"
    "    different meanings:\n"
    "    \n"
    "    - ``eq=True`` : Each item will be counted if ``item == pred``, the `pred`\n"
    "      must not be omitted in this case.\n"
    "    - ``eq=False`` : If ``pred`` is not given or ``None`` then each item in\n"
    "      the iterable is counted.\n"
    "      If ``pred`` is given and not ``None`` then each item satisfying\n"
    "      ``if pred(item)`` is counted.\n"
    "\n"
    "    Default is ``None``.\n"
    "\n"
    "eq : :py:class:`bool`, optional\n"
    "    If ``True`` compare each item in the `iterable` to `pred` instead of\n"
    "    calling ``pred(item)``.\n"
    "    Default is ``False``.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "number : number\n"
    "    The number of times the predicate is ``True``.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "To count how many elements are within an `iterable`::\n"
    "\n"
    "    >>> from iteration_utilities import count_items\n"
    "    >>> count_items([0, 0, '', {}, [], 2])\n"
    "    6\n"
    "\n"
    "To count the number of truthy values::\n"
    "\n"
    "    >>> count_items([0, 0, '', {}, [], 2], pred=bool)\n"
    "    1\n"
    "\n"
    "To count the number of values satisfying a condition::\n"
    "\n"
    "    >>> def smaller5(val): return val < 5\n"
    "    >>> count_items([1, 2, 3, 4, 5, 6, 6, 7], smaller5)\n"
    "    4\n"
    "\n"
    "To count the number of values equal to another value::\n"
    "\n"
    "    >>> count_items([1, 2, 3, 4, 5, 6, 6, 7], 6, True)\n"
    "    2\n");

PyDoc_STRVAR(
    PyIU_DotProduct_doc,
    "dotproduct(vec1, vec2)\n"
    "--\n\n"
    "Dot product (matrix multiplication) of two vectors.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "vec1, vec2 : iterable\n"
    "    Any `iterables` to calculate the dot product. Positional-only parameter.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "dotproduct : number\n"
    "    The dot product - the sum of the element-wise multiplication.\n"
    "\n"
    "Examples\n"
    "--------\n"
    ">>> from iteration_utilities import dotproduct\n"
    ">>> dotproduct([1,2,3,4], [1,2,3,4])\n"
    "30\n");

PyDoc_STRVAR(
    PyIU_Groupby_doc,
    "groupedby(iterable, key, keep=None, reduce=None, reducestart=None)\n"
    "--\n\n"
    "Group values of `iterable` by a `key` function as dictionary.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "iterable : iterable\n"
    "    The `iterable` to group by a `key` function.\n"
    "\n"
    "key : callable\n"
    "    The items of the `iterable` are grouped by the ``key(item)``.\n"
    "\n"
    "keep : callable, optional\n"
    "    If given append only the result of ``keep(item)`` instead of ``item``.\n"
    "\n"
    "reduce : callable, optional\n"
    "    If given then instead of returning a list of all ``items`` reduce them\n"
    "    using the binary `reduce` function. This works like the `func` parameter\n"
    "    in :py:func:`functools.reduce`.\n"
    "\n"
    "reducestart : any type, optional\n"
    "    If given (even as ``None``) it will be interpreted as start value for the\n"
    "    `reduce` function.\n"
    "    \n"
    "    .. note::\n"
    "       Can only be specified if `reduce` is given.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "grouped : dict\n"
    "    A dictionary where the `keys` represent the ``key(item)`` and the `values`\n"
    "    are lists containing all ``items`` having the same `key`.\n"
    "\n"
    "Notes\n"
    "-----\n"
    "This function differs from :py:func:`itertools.groupby` in several ways: (1) This\n"
    "function is eager (consumes the `iterable` in one go) and (2) the itertools\n"
    "function only groups the `iterable` locally.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "A simple example::\n"
    "\n"
    "    >>> from iteration_utilities import groupedby\n"
    "    >>> from operator import itemgetter, add\n"
    "    >>> dct = groupedby(['a', 'bac', 'ba', 'ab', 'abc'], key=itemgetter(0))\n"
    "    >>> dct['a']\n"
    "    ['a', 'ab', 'abc']\n"
    "    >>> dct['b']\n"
    "    ['bac', 'ba']\n"
    "\n"
    "One could also specify a `keep` function::\n"
    "\n"
    "    >>> dct = groupedby(['a', 'bac', 'ba', 'ab', 'abc'], key=itemgetter(0), keep=len)\n"
    "    >>> dct['a']\n"
    "    [1, 2, 3]\n"
    "    >>> dct['b']\n"
    "    [3, 2]\n"
    "\n"
    "Or reduce all values for one key::\n"
    "\n"
    "    >>> from iteration_utilities import is_even\n"
    "    >>> dct = groupedby([1, 2, 3, 4, 5], key=is_even, reduce=add)\n"
    "    >>> dct[True]  # 2 + 4\n"
    "    6\n"
    "    >>> dct[False]  # 1 + 3 + 5\n"
    "    9\n"
    "\n"
    "using `reduce` also allows to specify a start value::\n"
    "\n"
    "    >>> dct = groupedby([1, 2, 3, 4, 5], key=is_even, reduce=add, reducestart=7)\n"
    "    >>> dct[True]  # 7 + 2 + 4\n"
    "    13\n"
    "    >>> dct[False]  # 7 + 1 + 3 + 5\n"
    "    16\n");

PyDoc_STRVAR(
    PyIU_MinMax_doc,
    "minmax(iterable, /, key, default)\n"
    "--\n\n"
    "Computes the minimum and maximum values in one-pass using only\n"
    "``1.5*len(iterable)`` comparisons. Recipe based on the snippet\n"
    "of Raymond Hettinger ([0]_) but significantly modified.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "iterable : iterable\n"
    "    The `iterable` for which to calculate the minimum and maximum.\n"
    "\n"
    "    .. note::\n"
    "        Instead of one `iterable` it is also possible to pass the values (at\n"
    "        least 2) as positional arguments.\n"
    "\n"
    "key : callable, optional\n"
    "    If not given then compare the values, otherwise compare ``key(item)``.\n"
    "\n"
    "default : any type, optional\n"
    "    If not given raise ``ValueError`` if the `iterable` is empty otherwise\n"
    "    return ``(default, default)``\n"
    "\n"
    "Returns\n"
    "-------\n"
    "minimum : any type\n"
    "    The `minimum` of the `iterable`.\n"
    "\n"
    "maximum : any type\n"
    "    The `maximum` of the `iterable`.\n"
    "\n"
    "Raises\n"
    "------\n"
    "ValueError\n"
    "    If `iterable` is empty and no `default` is given.\n"
    "\n"
    "See also\n"
    "--------\n"
    "min : Calculate the minimum of an iterable.\n"
    "\n"
    "max : Calculate the maximum of an iterable.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "This function calculates the minimum (:py:func:`min`) and maximum\n"
    "(:py:func:`max`) of an `iterable`::\n"
    "\n"
    "    >>> from iteration_utilities import minmax\n"
    "    >>> minmax([2,1,3,5,4])\n"
    "    (1, 5)\n"
    "\n"
    "or pass in the values as arguments::\n"
    "\n"
    "    >>> minmax(2, 1, -1, 5, 4)\n"
    "    (-1, 5)\n"
    "\n"
    "If the iterable is empty `default` is returned::\n"
    "\n"
    "    >>> minmax([], default=0)\n"
    "    (0, 0)\n"
    "\n"
    "Like the builtin functions it also supports a `key` argument::\n"
    "\n"
    "    >>> import operator\n"
    "    >>> seq = [(3, 2), (5, 1), (10, 3), (8, 5), (3, 4)]\n"
    "    >>> minmax(seq, key=operator.itemgetter(1))\n"
    "    ((5, 1), (8, 5))\n"
    "\n"
    "References\n"
    "----------\n"
    ".. [0] http://code.activestate.com/recipes/577916/\n");

PyDoc_STRVAR(
    PyIU_One_doc,
    "one(iterable, /)\n"
    "--\n\n"
    "Return the first value in the `iterable` and expects it only contains one element.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "iterable : iterable\n"
    "    The `iterable` from which to get the one item.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "one : any type\n"
    "    The first value.\n"
    "\n"
    "Raises\n"
    "-------\n"
    "ValueError :\n"
    "    If the `iterable` contains no items or more than one item.\n"
    "\n"
    "Examples\n"
    "--------\n"
    "Some basic examples::\n"
    "\n"
    "    >>> from iteration_utilities import one\n"
    "    >>> one([0])\n"
    "    0\n"
    "    >>> one('b')\n"
    "    'b'\n"
    "\n"
    ".. warning::\n"
    "    :py:func:`~iteration_utilities.one` will access the first two values of \n"
    "    the `iterable` so it should only be used if the `iterable` must only \n"
    "    contain one item!\n");

PyDoc_STRVAR(
    PyIU_Partition_doc,
    "partition(iterable, pred=None)\n"
    "--\n\n"
    "Use a predicate to partition entries into ``False`` entries and ``True``\n"
    "entries.\n"
    "\n"
    "Parameters\n"
    "----------\n"
    "iterable : iterable\n"
    "    `Iterable` to partition.\n"
    "\n"
    "pred : callable or None, optional\n"
    "    The predicate which determines the partition.\n"
    "    Default is ``None``.\n"
    "\n"
    "Returns\n"
    "-------\n"
    "false_values : list\n"
    "    An list containing the values for which the `pred` was False.\n"
    "\n"
    "true_values : list\n"
    "    An list containing the values for which the `pred` was True.\n"
    "\n"
    "See also\n"
    "--------\n"
    ".ipartition : Generator variant of :py:func:`~iteration_utilities.partition`.\n"
    "\n"
    "Examples\n"
    "--------\n"
    ">>> from iteration_utilities import partition\n"
    ">>> def is_odd(val): return val % 2\n"
    ">>> partition(range(10), is_odd)\n"
    "([0, 2, 4, 6, 8], [1, 3, 5, 7, 9])\n"
    "\n"
    ".. warning::\n"
    "    In case the `pred` is expensive then \n"
    "    :py:func:`~iteration_utilities.partition` can be noticeable\n"
    "    faster than :py:func:`~iteration_utilities.ipartition`.\n");

#ifdef __cplusplus
}
#endif

#endif
