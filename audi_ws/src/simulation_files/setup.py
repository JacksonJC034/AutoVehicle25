from setuptools import find_packages, setup

package_name = 'racecar_controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=['simulation_files'],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dliujm',
    maintainer_email='dliujm@umich.edu',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'simulation = simulation_files.simulation:main',
        ],
    },
)
