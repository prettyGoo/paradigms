from abc import ABCMeta, abstractmethod
import inspect


class WriteOnlyDecorator(metaclass=ABCMeta):
    def __init__(self, decoratee, only_cls):
        self._decoratee = decoratee
        self.only_cls = only_cls
        setattr(self._decoratee, 'write_only', self.write_only)

    def __getattr__(self, name):
        return getattr(self._decoratee, name)

    def write_only(self):
        with open(self._decoratee.stdout_path, 'w') as f:
            active_node = self._decoratee.source.head

            while active_node is not None:
                data = active_node.get_data()
                if active_node.data.id is self.only_cls.id:
                    print(data, file=f)

                active_node = active_node.get_next()


class MultiDecorator(metaclass=ABCMeta):
    def __init__(self, decoratee):
        self._decoratee = decoratee
        setattr(self._decoratee, 'multi', self.multi)

    def __getattr__(self, name):
        return getattr(self._decoratee, name)

    def multi(self):
        with open(self._decoratee.stdout_path, 'w') as f:
            active_node = self._decoratee.source.head

            while active_node is not None:
                data = active_node.data._multi(active_node.data)
                print(data, file=f)

                next_node = active_node.next

                while next_node is not None:
                    data = active_node.data._multi(next_node.data)
                    print(data, file=f)

                    next_node = next_node.next
                active_node = active_node.next
