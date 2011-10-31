# TODO: License GPL, also in setup() call

import os
import sys
from wrappyr import get_version

if sys.version_info[:2] < (2, 6):
    msg = ("Wrappyr requires Python 2.6 or better, you are attempting to "
               "install it using version %s.  Please install with a "
               "supported version" % sys.version)
    sys.stderr.write(msg)
    sys.exit(1)

requires = ['lxml']
if sys.version_info[:2] < (2, 7):
    requires.extend(('argparse', 'importlib'))

tests_require = requires[:]
if sys.version_info[:2] < (2, 7):
    tests_require += ['unittest2', 'importlib']

from setuptools import setup, find_packages
here = os.path.abspath(os.path.normpath(os.path.dirname(__file__)))

DESC = """\
Wrappyr is a collection of tools that aims to provide
tight both-way integration between C/C++ and Python """

CLASSIFIERS = [ # TODO: Find right classifiers
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: BSD License',
        'Programming Language :: C',
        'Programming Language :: C++',
        'Programming Language :: Python',
        'Operating System :: POSIX',
        'Topic :: Software Development :: Code Generators',
        ]

wrappyr_version = get_version()

dist = setup(
        name = 'wrappyr',
        version = wrappyr_version,
        url = 'http://www.shishkabab.net/wrappyr.html',
        description = "A collection of tools providing tight integration between C/C++ and Python",
        long_description = DESC,
        classifiers = CLASSIFIERS,
        author = "Vincent den Boer",
        author_email = "vincent@shishkabab.net",
        maintainer = "Vincent den Boer",
        maintainer_email = "vincent@shishkabab.net",
        package_dir = {'wrappyr': 'wrappyr'},
        packages = find_packages(here),
        # put data files in egg 'doc' dir
        data_files=[ ('doc', [
                'README.rst',
                'TODO.rst',
                ]
        )],
        install_requires = requires,
        tests_require = tests_require,
        include_package_data = True,
        zip_safe = False,
        namespace_packages = ['wrappyr'],
        test_suite = "wrappyr.tests",
        entry_points = {
         'console_scripts': [
                 'wrappyr_generate = wrappyr.generate:main',
                 ],
          },
        )
