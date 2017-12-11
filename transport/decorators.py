from abc import ABCMeta, abstractmethod
import inspect


class SpeedDecorator(metaclass=ABCMeta):
    def __init__(self, decoratee, value):
        self._decoratee = decoratee
        setattr(self._decoratee, 'speed', value)

    def __getattr__(self, name):
        return getattr(self._decoratee, name)


class WeightToPowerDecorator(metaclass=ABCMeta):
    def __init__(self, decoratee):
        self._decoratee = decoratee
        setattr(self._decoratee, 'calc_value', self.calc_value)

    def __getattr__(self, name):
        return getattr(self._decoratee, name)

    def calc_value(self):
        return self._decoratee.weight / self._decoratee.power
