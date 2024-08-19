from setuptools import setup, find_packages

setup(
    name='3D Minecraft-Style Sandbox Game',
    version='1.0',
    packages=find_packages(),
    install_requires=['pygame', 'PyOpenGL', 'PyOpenGL-accelerate'],
    entry_points={
        'console_scripts': [
            'game=game:main',
        ],
    },
)