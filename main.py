from abc import ABCMeta, abstractmethod


class AbstractTransport(metaclass=ABCMeta):

    @abstractmethod
    def input_data(self):
        pass

    @abstractmethod
    def output_date(self):
        pass


class Bus(AbstractTransport):
    id = 0

    def __init__(self, speed, power):

        self.speed = speed
        self.power = power

    def input_data(self):
        pass

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



import sys, inspect

with open('in', 'r') as f:
    while True:
        raw_data = f.readline().replace('\n', '')
        if raw_data:
            for name, class_obj in inspect.getmembers(sys.modules[__name__]):
                if inspect.isclass(class_obj) and class_obj != ABCMeta and class_obj != AbstractTransport:
                    if class_obj.id == int(raw_data):
                        print(name, raw_data)
        else:
            break