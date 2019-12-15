######################################################################
# Qt Project for phonebook
######################################################################

QT += core gui widgets

TEMPLATE = app
TARGET = phonebook
INCLUDEPATH += .

# Input
HEADERS += entry.h newNumber.h phonebook.h
SOURCES += entry.cpp main.cpp newNumber.cpp phonebook.cpp
