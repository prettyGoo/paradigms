from abc import ABCMeta, abstractmethod
import inspect
from transport.abstract_transport import AbstractTransport
from transport.bus import Bus
from transport.truck import Truck

import transport
package = transport

import pkgutil
submodules = []
for importer, modname, ispkg in pkgutil.walk_packages(path=package.__path__,
                                                      prefix=package.__name__+'.',
                                                      onerror=lambda x: None):
    submodules.append(modname)



# class AbstractTransport(metaclass=ABCMeta):
#
#     # @abstractmethod
#     def __str__(self):
#         string = "{}: ".format(self.__class__.__name__)
#
#         extend_string = lambda string, extenders: string + reduce((lambda s, ex: s + ' {} = {}'.format(ex[0], ex[1])), extenders)
#
#         print(extend_string(string, [('a', 'a'), ('b', 'bbb')]))
#         #
#         # for i in inspect.getmembers(self):
#         #     if not i[0].startswith('_'):
#         #         if not inspect.ismethod(i[1]):
#         #             string += '{} = {} '.format(i[0], i[1])
#         #
#         # return string
#
#     @abstractmethod
#     def output_date(self):
#         pass


# class Bus(AbstractTransport):
#     id = 0
#
#     def __init__(self, speed, power):
#
#         self.speed = speed
#         self.power = power
#
#     def output_date(self):
#         pass
#
#
# class Truck(AbstractTransport):
#     id = 1
#
#     def __init__(self, speed, power):
#         self.speed = speed
#         self.power = power
#
#     def input_data(self):
#         pass
#
#     def output_date(self):
#         pass
#
#
# class Car(AbstractTransport):
#     id = 1
#
#     def __init__(self, speed, power):
#         self.speed = speed
#         self.power = power
#
#     def input_data(self):
#         pass
#
#     def output_date(self):
#         pass


container = []
import sys, inspect

b = Bus(1, 1)

with open('in', 'r') as f:
    while True:
        raw_data = f.readline().replace('\n', '')
        if raw_data:
            for submod in submodules:
                for name, class_obj in inspect.getmembers(sys.modules[submod]):
                    if inspect.isclass(class_obj) and not inspect.isabstract(class_obj) and class_obj is not ABCMeta:
                        if class_obj.id == int(raw_data):
                            container.append(globals()[name](4, 6))
                        # print(name, raw_data)
        else:
            break


f.close()


with open('out', 'w') as f:
    for elem in container:
        print(elem)
        f.write(str(elem) + '\n')
#
f.close()