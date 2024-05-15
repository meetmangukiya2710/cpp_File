#include <iostream>
#include <string>

/* Car parts */
class Wheel
{
    public:
        int size;
};

class Engine
{
    public:
        int horsepower;
};

class Body
{
    public:
        std::string shape;
};
class Car
{
    public:
        Wheel*   wheels[4];
        Engine*  engine;
        Body* body;
    
        void specifications()
        {
            std::cout << "body:" << body->shape << std::endl;
            std::cout << "engine horsepower:" << engine->horsepower << std::endl;
            std::cout << "tire size:" << wheels[0]->size << "'" << std::endl;
        }
};

class Builder
{
    public:
        virtual Wheel* getWheel() = 0;
        virtual Engine* getEngine() = 0;
        virtual Body* getBody() = 0;
};

class Director
{
    Builder* builder;

    public:
        void setBuilder(Builder* newBuilder)
        {
            builder = newBuilder;
        }

        Car* getCar()
        {
            Car* car = new Car();

            car->body = builder->getBody();

            car->engine = builder->getEngine();

            car->wheels[0] = builder->getWheel();
            car->wheels[1] = builder->getWheel();
            car->wheels[2] = builder->getWheel();
            car->wheels[3] = builder->getWheel();

            return car;
        }
};

class JeepBuilder : public Builder
{
    public:
        Wheel* getWheel()
        {
            Wheel* wheel = new Wheel();
            wheel->size = 22;
            return wheel;
        }

        Engine* getEngine()
        {
            Engine* engine = new Engine();
            engine->horsepower = 400;
            return engine;
        }

        Body* getBody()
        {
            Body* body = new Body();
            body->shape = "SUV";
        }
};

class NissanBuilder : public Builder
{
    public:
        Wheel* getWheel()
        {
            Wheel* wheel = new Wheel();
            wheel->size = 16;
            return wheel;
        }

        Engine* getEngine()
        {
            Engine* engine = new Engine();
            engine->horsepower = 85;
            return engine;
        }

        Body* getBody()
        {
            Body* body = new Body();
            body->shape = "hatchback";
        }
};


int main()
{
    Car* car;

    Director director;

    JeepBuilder jeepBuilder;
    NissanBuilder nissanBuilder;

    std::cout << "Jeep" << std::endl;
    director.setBuilder(&jeepBuilder);
    car = director.getCar();
    car->specifications();

    std::cout << std::endl;

    /* Build a Nissan */
    std::cout << "Nissan" << std::endl;
    director.setBuilder(&nissanBuilder); 
    car = director.getCar();
    car->specifications();

    return 0;
}
