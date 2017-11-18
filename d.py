# -*- coding: cp1251 -*-
class AbstractTransport:
    """ Абстрактный блок
    """

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


class CapacityDecorator(AbstractTransportDecorator):
    def __init__(self, decoratee, capacity):
        super().__init__(decoratee)

        self.capacity = capacity

    def abstract(self):
        AbstractTransportDecorator.abstract(self)


class CalcDecorator(AbstractTransportDecorator):
    def __init__(self, decoratee):
        super().__init__(decoratee)

    def abstract(self):
        AbstractTransportDecorator.abstract(self)

    def calc(self):

        return self._decoratee.speed * self._decoratee.power



# терминальный блок
bus = Bus(14, 1)
# блок - процесс
truck = Truck(2, 2)

# Применим LabelDecorator к терминальному блоку
cap_bus = CapacityDecorator(bus, 100)
print(cap_bus.capacity)


# Применим BorderDecorator к терминальному блоку, после применения LabelDecorator
cap_calc_bus = CalcDecorator(cap_bus)
# print(cap_calc_bus)
print(cap_calc_bus.calc())
#
# labelDecorator.draw()
# borderDecorator1.draw()
# borderDecorator2.draw()
