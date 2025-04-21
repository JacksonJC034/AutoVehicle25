import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/fishros/AutoVehicle25/audi_ws/install/vehicle_state_publisher'
