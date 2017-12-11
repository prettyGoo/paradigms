from abc import ABCMeta, abstractmethod
import inspect


class SortDecorator(metaclass=ABCMeta):
    def __init__(self, decoratee):
        self._decoratee = decoratee
        setattr(self._decoratee, 'sort', self.sort)

    def __getattr__(self, name):
        return getattr(self._decoratee, name)

    def sort(self):
        container = self._decoratee

        active_node = container.head

        while active_node is not None:
            next_node = active_node.next

            while next_node is not None:
                if active_node.data.calc_value() < next_node.data.calc_value():
                    active_node.data, next_node.data = next_node.data, active_node.data

                next_node = next_node.next

            active_node = active_node.next
