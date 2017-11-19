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
        return self._decoratee.weight / self._decoratee.power