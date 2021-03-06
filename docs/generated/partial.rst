partial
=======

.. currentmodule:: iteration_utilities

.. autoclass:: partial

   .. method:: __call__(*additional_args, **additional_kwargs)

      Returns ``func(*all_args, **all_kwargs)`` using :py:attr:`.func`. The
      ``all_args`` are the :py:attr:`.args` combined with the
      ``additional_args``. Likewise the ``all_kwargs`` is a mapping created
      from the :py:attr:`keywords` with the ``additional_kwargs``.

   .. method:: __sizeof__()

      Returns size of the instance in memory, in bytes.

   .. attribute:: _

      (:py:data:`~iteration_utilities.Placeholder`) Allows easy access to a
      placeholder without having to import
      :py:data:`~iteration_utilities.Placeholder`.

   .. attribute:: __dict__

      (:py:class:`dict`) instances have a normal ``__dict__`` member and
      support instance attributes.