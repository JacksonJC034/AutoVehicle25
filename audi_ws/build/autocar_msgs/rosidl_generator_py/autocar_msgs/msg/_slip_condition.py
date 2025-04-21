# generated from rosidl_generator_py/resource/_idl.py.em
# with input from autocar_msgs:msg/SlipCondition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SlipCondition(type):
    """Metaclass of message 'SlipCondition'."""

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
                'autocar_msgs.msg.SlipCondition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__slip_condition
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__slip_condition
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__slip_condition
            cls._TYPE_SUPPORT = module.type_support_msg__msg__slip_condition
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__slip_condition

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


class SlipCondition(metaclass=Metaclass_SlipCondition):
    """Message class 'SlipCondition'."""

    __slots__ = [
        '_header',
        '_front_saturated',
        '_rear_saturated',
        '_front_delta_alpha',
        '_front_delta_k',
        '_rear_delta_alpha',
        '_rear_delta_k',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'front_saturated': 'boolean',
        'rear_saturated': 'boolean',
        'front_delta_alpha': 'double',
        'front_delta_k': 'double',
        'rear_delta_alpha': 'double',
        'rear_delta_k': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
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
        self.front_saturated = kwargs.get('front_saturated', bool())
        self.rear_saturated = kwargs.get('rear_saturated', bool())
        self.front_delta_alpha = kwargs.get('front_delta_alpha', float())
        self.front_delta_k = kwargs.get('front_delta_k', float())
        self.rear_delta_alpha = kwargs.get('rear_delta_alpha', float())
        self.rear_delta_k = kwargs.get('rear_delta_k', float())

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
        if self.front_saturated != other.front_saturated:
            return False
        if self.rear_saturated != other.rear_saturated:
            return False
        if self.front_delta_alpha != other.front_delta_alpha:
            return False
        if self.front_delta_k != other.front_delta_k:
            return False
        if self.rear_delta_alpha != other.rear_delta_alpha:
            return False
        if self.rear_delta_k != other.rear_delta_k:
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
    def front_saturated(self):
        """Message field 'front_saturated'."""
        return self._front_saturated

    @front_saturated.setter
    def front_saturated(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'front_saturated' field must be of type 'bool'"
        self._front_saturated = value

    @builtins.property
    def rear_saturated(self):
        """Message field 'rear_saturated'."""
        return self._rear_saturated

    @rear_saturated.setter
    def rear_saturated(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'rear_saturated' field must be of type 'bool'"
        self._rear_saturated = value

    @builtins.property
    def front_delta_alpha(self):
        """Message field 'front_delta_alpha'."""
        return self._front_delta_alpha

    @front_delta_alpha.setter
    def front_delta_alpha(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'front_delta_alpha' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'front_delta_alpha' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._front_delta_alpha = value

    @builtins.property
    def front_delta_k(self):
        """Message field 'front_delta_k'."""
        return self._front_delta_k

    @front_delta_k.setter
    def front_delta_k(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'front_delta_k' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'front_delta_k' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._front_delta_k = value

    @builtins.property
    def rear_delta_alpha(self):
        """Message field 'rear_delta_alpha'."""
        return self._rear_delta_alpha

    @rear_delta_alpha.setter
    def rear_delta_alpha(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rear_delta_alpha' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rear_delta_alpha' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rear_delta_alpha = value

    @builtins.property
    def rear_delta_k(self):
        """Message field 'rear_delta_k'."""
        return self._rear_delta_k

    @rear_delta_k.setter
    def rear_delta_k(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rear_delta_k' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rear_delta_k' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rear_delta_k = value
