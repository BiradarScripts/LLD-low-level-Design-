#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DocumentElement {
public:
    virtual string render() = 0;
    virtual ~DocumentElement() {}
};

class TextElement : public DocumentElement {
public:
    string render() override {
        return "Rendering text element";
    }
};

class ImageElement : public DocumentElement {
public:
    string render() override {
        return "Rendering image element";
    }
};

class Document{
    private:
    vector<DocumentElement*> elements;
    public:
    void addElement(DocumentElement* element) {
        elements.push_back(element);
    }

    vector<DocumentElement*> getElements() {
        return elements;
    }
};

class PersistenceManager{
    public:
        virtual void save()=0;
        virtual ~PersistenceManager() {}
};


class SaveTofFile : public PersistenceManager{
    public:
        void save() override {
            cout << "Saving document to file" << endl;
        }
};

class SaveToCloud : public PersistenceManager{
    public:
        void save() override {
            cout << "Saving document to cloud" << endl;
        }      
};


class DocumentEditor{
    private:
        Document *document;
        PersistenceManager* persistence;
    public:
        DocumentEditor(Document*doc, PersistenceManager* persistenceManager) {
             this->persistence = persistenceManager;
            this->document = doc;
        }

        void addText(DocumentElement* element) {
            document->addElement(element);
        }

        void addImage(DocumentElement* element) {
            document->addElement(element);
        }

        void renderDocument() {
            vector<DocumentElement*> elements = document->getElements();
            for(DocumentElement* element : elements) {
                cout << element->render() << endl;
            }
        }

        void saveDocument() {
            persistence->save();
        }
};