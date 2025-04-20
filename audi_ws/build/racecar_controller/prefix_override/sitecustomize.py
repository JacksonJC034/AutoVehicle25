import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/dliujm/um_files/rob_498_av/AutoVehicle25/audi_ws/install/racecar_controller'
