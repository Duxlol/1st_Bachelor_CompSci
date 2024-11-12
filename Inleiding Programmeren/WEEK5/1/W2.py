class Point:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def print(self):
        print(f"({self.x},{self.y})")


if __name__ == "__main__":
    p1 = Point(-1,4)
    p1.print()

    p2 = Point(-2,-4)
    p2.print()

    p3 = Point(3,-5)
    p3.print()