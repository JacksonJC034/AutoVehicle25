# generated from rosidl_generator_py/resource/_idl.py.em
# with input from autocar_msgs:msg/TireSlips.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TireSlips(type):
    """Metaclass of message 'TireSlips'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('autocar_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autocar_msgs.msg.TireSlips')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__tire_slips
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__tire_slips
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__tire_slips
            cls._TYPE_SUPPORT = module.type_support_msg__msg__tire_slips
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__tire_slips

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TireSlips(metaclass=Metaclass_TireSlips):
    """Message class 'TireSlips'."""

    __slots__ = [
        '_header',
        '_front_alpha',
        '_rear_alpha',
        '_front_k',
        '_rear_k',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'front_alpha': 'double',
        'rear_alpha': 'double',
        'front_k': 'double',
        'rear_k': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.front_alpha = kwargs.get('front_alpha', float())
        self.rear_alpha = kwargs.get('rear_alpha', float())
        self.front_k = kwargs.get('front_k', float())
        self.rear_k = kwargs.get('rear_k', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.front_alpha != other.front_alpha:
            return False
        if self.rear_alpha != other.rear_alpha:
            return False
        if self.front_k != other.front_k:
            return False
        if self.rear_k != other.rear_k:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def front_alpha(self):
        """Message field 'front_alpha'."""
        return self._front_alpha

    @front_alpha.setter
    def front_alpha(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'front_alpha' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'front_alpha' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._front_alpha = value

    @builtins.property
    def rear_alpha(self):
        """Message field 'rear_alpha'."""
        return self._rear_alpha

    @rear_alpha.setter
    def rear_alpha(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rear_alpha' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rear_alpha' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rear_alpha = value

    @builtins.property
    def front_k(self):
        """Message field 'front_k'."""
        return self._front_k

    @front_k.setter
    def front_k(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'front_k' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'front_k' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._front_k = value

    @builtins.property
    def rear_k(self):
        """Message field 'rear_k'."""
        return self._rear_k

    @rear_k.setter
    def rear_k(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rear_k' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rear_k' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rear_k = value
