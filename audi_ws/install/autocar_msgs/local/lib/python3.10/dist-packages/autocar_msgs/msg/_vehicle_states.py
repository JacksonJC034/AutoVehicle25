# generated from rosidl_generator_py/resource/_idl.py.em
# with input from autocar_msgs:msg/VehicleStates.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VehicleStates(type):
    """Metaclass of message 'VehicleStates'."""

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
                'autocar_msgs.msg.VehicleStates')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vehicle_states
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vehicle_states
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vehicle_states
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vehicle_states
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vehicle_states

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VehicleStates(metaclass=Metaclass_VehicleStates):
    """Message class 'VehicleStates'."""

    __slots__ = [
        '_time',
        '_x',
        '_y',
        '_theta',
        '_fr_angle',
        '_fl_angle',
        '_br_angle',
        '_bl_angle',
    ]

    _fields_and_field_types = {
        'time': 'double',
        'x': 'double',
        'y': 'double',
        'theta': 'double',
        'fr_angle': 'double',
        'fl_angle': 'double',
        'br_angle': 'double',
        'bl_angle': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.time = kwargs.get('time', float())
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.theta = kwargs.get('theta', float())
        self.fr_angle = kwargs.get('fr_angle', float())
        self.fl_angle = kwargs.get('fl_angle', float())
        self.br_angle = kwargs.get('br_angle', float())
        self.bl_angle = kwargs.get('bl_angle', float())

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
        if self.time != other.time:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.theta != other.theta:
            return False
        if self.fr_angle != other.fr_angle:
            return False
        if self.fl_angle != other.fl_angle:
            return False
        if self.br_angle != other.br_angle:
            return False
        if self.bl_angle != other.bl_angle:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def time(self):
        """Message field 'time'."""
        return self._time

    @time.setter
    def time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._time = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y = value

    @builtins.property
    def theta(self):
        """Message field 'theta'."""
        return self._theta

    @theta.setter
    def theta(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'theta' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'theta' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._theta = value

    @builtins.property
    def fr_angle(self):
        """Message field 'fr_angle'."""
        return self._fr_angle

    @fr_angle.setter
    def fr_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'fr_angle' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'fr_angle' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._fr_angle = value

    @builtins.property
    def fl_angle(self):
        """Message field 'fl_angle'."""
        return self._fl_angle

    @fl_angle.setter
    def fl_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'fl_angle' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'fl_angle' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._fl_angle = value

    @builtins.property
    def br_angle(self):
        """Message field 'br_angle'."""
        return self._br_angle

    @br_angle.setter
    def br_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'br_angle' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'br_angle' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._br_angle = value

    @builtins.property
    def bl_angle(self):
        """Message field 'bl_angle'."""
        return self._bl_angle

    @bl_angle.setter
    def bl_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bl_angle' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'bl_angle' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._bl_angle = value
