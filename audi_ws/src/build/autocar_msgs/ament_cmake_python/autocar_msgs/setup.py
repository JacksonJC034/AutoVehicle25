from setuptools import find_packages
from setuptools import setup

setup(
    name='autocar_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('autocar_msgs', 'autocar_msgs.*')),
)
