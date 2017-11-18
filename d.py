class AbstractTransport:

    def abstract(self):
        raise NotImplementedError()


class Bus(AbstractTransport):
    id = 0

    def __init__(self, speed, power):
        self.speed = speed
        self.power = power

    def abstract(self):
        pass
        "Terminator block drawing ... "


class Truck(AbstractTransport):
    id = 0

    def __init__(self, speed, power):
        self.speed = speed
        self.power = power

    def abstract(self):
        pass
        "Process block drawing ... "


class AbstractTransportDecorator(AbstractTransport):
    def __init__(self, decoratee):
        self._decoratee = decoratee

    def abstract(self):
        self._decoratee.abstract()


class SubDecorator(AbstractTransportDecorator):

    def abstract(self):
        self.abstract(self)

    def sub(self):
        return self._decoratee.speed - self._decoratee.power


class CalcDecorator(AbstractTransportDecorator):
    def abstract(self):
        self.abstract(self)

    def calc(self):
        return self._decoratee.speed * self._decoratee.power




# bus = Bus(14, 1)
# truck = Truck(2, 2)
#
# calc_bus = CalcDecorator(bus)
# print(calc_bus.calc())
#
# calc_sub_bus = SubDecorator(calc_bus)
# print(calc_sub_bus.calc())


# cap_calc_bus = CalcDecorator(cap_bus)
# # print(cap_calc_bus)
# print(cap_calc_bus.calc())
#
# labelDecorator.draw()
# borderDecorator1.draw()
# borderDecorator2.draw()


# class Bus(AbstractTransport):
#     def __init__(self, speed, power):
#         self.speed = speed
#         self.power = power
#
#     # def f1(self):
#     #     print("original f1")
#     #
#     # def f2(self):
#     #     print( "original f2 %s" % self.a)
#
#
# class CapacityDecorator(object):
#     def __init__(self, decoratee):
#         self._decoratee = decoratee
#
#     def f1(self):
#         print ("decorated f1")
#         self._decoratee.f1()
#
#     def __getattr__(self, name):
#         return getattr(self._decoratee, name)
#
#
# bus = Bus(1, 2)
# bus_with_capacity = CapacityDecorator(bus)
# # v.f1()
# bus_with_capacity.f2()


class Bus(AbstractTransport):
    def __init__(self, speed, power):
        self.speed = speed
        self.power = power

    def f1(self):
        print("original f1")
    def f2(self):
        print("original f2")


class CapacityDecorator(object):
    def __init__(self, decoratee, c):
        self._decoratee = decoratee
        setattr(self._decoratee, 'capacity', c)

    def f1(self):
        print( "decorated f1")
        self._decoratee.f1()
    def __getattr__(self, name):
        return getattr(self._decoratee, name)


class CalcDecorator(object):
    def __init__(self, decoratee):
        self._decoratee = decoratee

    def calc(self):
        return self._decoratee.speed * self._decoratee.power

    def f2(self):
        print( "decorated f2")
        self._decoratee.f2()
    def __getattr__(self, name):
        return getattr(self._decoratee, name)


bus = Bus(70, 140)
# u1 = foo_decorator1(u)
# u1.f1()
# u1.f2()
#
# u2 = foo_decorator2(u)
# u2.f1()
# u2.f2()

v1 = CalcDecorator(bus)
print(v1.calc())
v2 = CapacityDecorator(v1, 34)
print(v2.capacity)
print(v2.calc())

v2.f1()
v2.f2()
