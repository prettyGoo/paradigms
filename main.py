from abc import ABCMeta, abstractmethod
import inspect


class AbstractTransport(metaclass=ABCMeta):

    # @abstractmethod
    def __str__(self):
        string = "{}: ".format(self.__class__.__name__, )
        for i in inspect.getmembers(self):
            if not i[0].startswith('_'):
                if not inspect.ismethod(i[1]):
                    string += '{} = {} '.format(i[0], i[1])

        return string

    @abstractmethod
    def output_date(self):
        pass


class Bus(AbstractTransport):
    id = 0

    def __init__(self, speed, power):

        self.speed = speed
        self.power = power

    def output_date(self):
        pass


class Truck(AbstractTransport):
    id = 1

    def __init__(self, speed, power):
        self.speed = speed
        self.power = power

    def input_data(self):
        pass

    def output_date(self):
        pass


class Car(AbstractTransport):
    id = 1

    def __init__(self, speed, power):
        self.speed = speed
        self.power = power

    def input_data(self):
        pass

    def output_date(self):
        pass


container = []
import sys, inspect

with open('in', 'r') as f:
    while True:
        raw_data = f.readline().replace('\n', '')
        if raw_data:
            for name, class_obj in inspect.getmembers(sys.modules[__name__]):
                if inspect.isclass(class_obj) and class_obj != ABCMeta and class_obj != AbstractTransport:
                    if class_obj.id == int(raw_data):
                        container.append(globals()[name](4, 6))
                        print(name, raw_data)
        else:
            break


f.close()


with open('out', 'w') as f:
    for elem in container:
        print(elem)
        f.write(str(elem) + '\n')

f.close()