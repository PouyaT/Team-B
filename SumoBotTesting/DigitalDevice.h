#ifndef DIGITALDEVICE_H
#define DIGITALDEVICE_H


class DigitalDevice
{
    public:
        DigitalDevice(int pinNum);
        int pin;
        virtual ~DigitalDevice();
        int read(pin);
        void write(pin);

    protected:

    private:
};

#endif // DIGITALDEVICE_H
