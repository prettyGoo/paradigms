class AbstractTransport:
    def __init__(self, power):
        self.power = power

    def abstract(self):
        raise NotImplementedError()


class Bus(AbstractTransport):
    def __init__(self, capacity, power):
        self.capacity = capacity
        super().__init__(power)


class Truck(AbstractTransport):
    def __init__(self, weight, power):
        self.weight = weight
        super().__init__(power)


# class CapacityDecorator(object):
#     def __init__(self, decoratee, c):
#         self._decoratee = decoratee
#         setattr(self._decoratee, 'capacity', c)
#
#     def f1(self):
#         print( "decorated f1")
#         self._decoratee.f1()
#     def __getattr__(self, name):
#         return getattr(self._decoratee, name)
#
#
# class CalcDecorator(object):
#     def __init__(self, decoratee):
#         self._decoratee = decoratee
#         # setattr(self._decoratee, 'calc', lambda self: self._decoratee.speed * self._decoratee.power)
#     #
#     def calc(self):
#         return self._decoratee.speed * self._decoratee.power
#
#     def f2(self):
#         print( "decorated f2")
#         self._decoratee.f2()
#     def __getattr__(self, name):
#         return getattr(self._decoratee, name)
from abc import ABCMeta, abstractmethod


class SpeedDecorator(metaclass=ABCMeta):
    def __init__(self, decoratee, value):
        self._decoratee = decoratee
        setattr(self._decoratee, 'speed', value)

    def __getattr__(self, name):
        return getattr(self._decoratee, name)


class WeightToPowerDecorator(metaclass=ABCMeta):
    def __init__(self, decoratee):
        self._decoratee = decoratee

    def __getattr__(self, name):
        return getattr(self._decoratee, name)

    @abstractmethod
    def weight_to_power(self):
        pass


class WeightToPowerBusDecorator(WeightToPowerDecorator):
    def __init__(self, decoratee):
        self._decoratee = decoratee

    def __getattr__(self, name):
        return getattr(self._decoratee, name)

    def weight_to_power(self):
        return 75 * self._decoratee.capacity / self._decoratee.power


class WeightToPowerTruckDecorator(WeightToPowerDecorator):
    def __init__(self, decoratee):
        self._decoratee = decoratee

    def __getattr__(self, name):
        return getattr(self._decoratee, name)

    def weight_to_power(self):
        return self._decoratee.capacity / self._decoratee.power


bus = Bus(70, 140)
bus_speed = SpeedDecorator(bus, 123)
print(bus_speed.speed)


bus_calc = WeightToPowerBusDecorator(bus)
print(bus_calc.weight_to_power())

bus_speed_calc = WeightToPowerBusDecorator(bus_speed)
print(bus_speed_calc.speed)
print(bus_speed_calc.weight_to_power())


# u1 = foo_decorator1(u)
# u1.f1()
# u1.f2()
#
# u2 = foo_decorator2(u)
# u2.f1()
# u2.f2()
#
# v1 = CalcDecorator(bus)
# print(v1.calc())
# v2 = CapacityDecorator(v1, 34)
# print(v2.capacity)
# print(v2.calc())
#
# v2.f1()
# v2.f2()
#
#
# truck = Truck(1, 2)
# cap_truck = CapacityDecorator(truck, 1223)
# print(cap_truck.capacity)