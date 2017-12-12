from .abstract_transport import AbstractTransport
from .decorators import SpeedDecorator, WeightToPowerDecorator, MultiDecorator


class BusInterface(AbstractTransport):
    """
    Interface for Buses
    """
    id = 0

    def __init__(self, *args):
        params = args[0]

        self.weight = params[0]
        super().__init__(params[1])

    def _abstractionize(self):
        pass


class Bus(BusInterface):
    """
    This is an object which might be decorated
    """
    def __init__(self, *args):
        super().__init__((args[0][:2]))

        # decorate an object below
        WeightToPowerDecorator(self)
        SpeedDecorator(self, args[0][2])
        MultiDecorator(self)
