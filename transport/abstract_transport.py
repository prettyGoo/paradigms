from abc import ABCMeta, abstractmethod
import inspect


class AbstractTransport(metaclass=ABCMeta):

    def __str__(self):
        self_name = self.__class__.__name__
        string = "{}: ".format(self_name)

        for i in inspect.getmembers(self):
            if not i[0].startswith('_'):
                if not inspect.ismethod(i[1]):
                    string += '{} = {} '.format(i[0], i[1])

        return string

    @abstractmethod
    def output_data(self):
        pass
