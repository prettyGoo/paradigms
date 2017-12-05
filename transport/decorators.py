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
        setattr(self._decoratee, 'weight_to_power', self.weight_to_power)

    def __getattr__(self, name):
        return getattr(self._decoratee, name)

    def weight_to_power(self):
        return self._decoratee.weight / self._decoratee.power
