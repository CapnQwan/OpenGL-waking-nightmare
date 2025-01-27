class Vector2 {
public:
    float x;
    float y;

public:
    Vector2();
    ~Vector2();

    float Magnitude();
    void Normalize();
    Vector2 Normalized();

    void Add(Vector2& vector);
    void Subtract(Vector2& vector);
    void Multiply(Vector2& vector);
    void Divide(Vector2& vector);
    void Scale(float scalar);

    float Dot(Vector2& vector);
    Vector2 Cross(Vector2& vector);

    float Distance(Vector2& vector);
    float Angle(Vector2& vector);
    
    Vector2 Clone();

    static void Normalize(Vector2& vector);

    static Vector2 zero();
    static Vector2 one();
    static Vector2 up();
    static Vector2 down();
    static Vector2 left();
    static Vector2 right();
}; 