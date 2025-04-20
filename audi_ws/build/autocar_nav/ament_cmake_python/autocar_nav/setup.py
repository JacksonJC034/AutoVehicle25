from setuptools import find_packages
from setuptools import setup

setup(
    name='autocar_nav',
    version='0.0.0',
    packages=find_packages(
        include=('autocar_nav', 'autocar_nav.*')),
)
