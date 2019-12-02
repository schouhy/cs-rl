#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


class Environment
{
private:
    bool m_Done;
public:
    Environment();
    ~Environment();

    //Functions
    void step();
    bool isDone() const;
};

#endif