from .abstract_transport import AbstractTransport
from .decorators import SpeedDecorator


class CarInterface(AbstractTransport):
    """
    Interface for Trucks
    """
    id = 2

    def __init__(self, *args):
        params = args[0]

        self.weight = params[0]
        super().__init__(params[1])

    def _abstractionize(self):
        pass


class Car(CarInterface):
    """
    This is an object which might be decorated
    """
    def __init__(self, *args):
        super().__init__((args[0][:2]))

        # decorate an object below
        # e.g. self = MyDecorator(self, decor_params)
