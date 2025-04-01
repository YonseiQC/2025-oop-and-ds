class Object;

class AbstractRenderer {
public:
	virtual void render_object(Object& obj) = 0;
};

class HTMLRenderer : public AbstractRenderer {
public:
	void render_object(Object& obj) override;
};

class PDFRenderer : public AbstractRenderer {
public:
	void render_object(Object& obj) override;
};

int main() {
	return 0;
}
