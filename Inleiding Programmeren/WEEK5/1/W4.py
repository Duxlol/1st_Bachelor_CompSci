from math import sqrt
class Point:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def print(self):
        print(f"({self.x},{self.y})")
    def reflect_x(self):
        return Point(self.x, -self.y)
    def distance(self,point):
        return sqrt((self.x-point.x)**2+(self.y-point.y)**2)
if __name__ == "__main__":
    p1 = Point(1,4)
    p2 = Point(-3,4)
    p3 = Point(-3,-5)
    p4 = Point(-3,-5)

    print(p1.distance(p2))
    print(p2.distance(p3))
    print(p3.distance(p2))
    print(p3.distance(p4))