#! /bin/sh

# set -x

_modules='
	conveyor.async
	conveyor.async.glib
	conveyor.async.qt
	conveyor.enum
	conveyor.event
	conveyor.printer
	conveyor.printer.dbus
	conveyor.process
	conveyor.toolpathgenerator
	conveyor.toolpathgenerator.dbus
'
_files='
	src/main/python/conveyor/async/__init__.py
	src/main/python/conveyor/async/glib.py
	src/main/python/conveyor/async/qt.py
	src/main/python/conveyor/enum.py
	src/main/python/conveyor/event.py
	src/main/python/conveyor/printer/__init__.py
	src/main/python/conveyor/printer/dbus.py
	src/main/python/conveyor/process.py
	src/main/python/conveyor/toolpathgenerator/__init__.py
	src/main/python/conveyor/toolpathgenerator/dbus.py
'

if [ ! -d obj/ ]
then
	mkdir obj/
fi

env PYTHONDONTWRITEBYTECODE=1 PYTHONPATH=src/main/python/ coverage run --branch -m unittest ${_modules}
_code=$?
env PYTHONDONTWRITEBYTECODE=1 PYTHONPATH=src/main/python/ coverage annotate -d obj/ ${_files}
env PYTHONDONTWRITEBYTECODE=1 PYTHONPATH=src/main/python/ coverage html -d obj/ ${_files}
env PYTHONDONTWRITEBYTECODE=1 PYTHONPATH=src/main/python/ coverage xml -o obj/coverage.xml ${_files}
env PYTHONDONTWRITEBYTECODE=1 PYTHONPATH=src/main/python/ coverage report ${_files}
exit ${_code}
