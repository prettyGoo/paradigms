from abc import ABCMeta, abstractmethod
import inspect


class AbstractTransport(metaclass=ABCMeta):

    def __init__(self, power):
        self.power = power

    def __str__(self):
        self_name = self.__class__.__name__
        string = "{}: ".format(self_name)

        for method_name, method in inspect.getmembers(self):
            if not self._is_private(method_name):
                if not self._is_method(method):
                    string += '{} = {} '.format(method_name, method)
                else:
                    string += '{} = {} '.format(method_name, method())

        return string

    def _is_private(self, member):
        return member.startswith('_')

    def _is_method(self, member):
        return inspect.ismethod(member)

    @abstractmethod
    def _abstractionize(self):
        pass
