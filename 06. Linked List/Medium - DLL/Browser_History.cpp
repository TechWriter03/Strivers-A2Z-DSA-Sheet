class Tab
{
public:
    string url;
    Tab* next;
    Tab* prev;
    Tab(string s)
    {
        url=s;
        next=NULL;
        prev=NULL;
    }
};

class BrowserHistory
{
public:
    Tab* current;
    BrowserHistory(string homepage)
    {
        Tab* head=new Tab(homepage);
        current=head;
    }
    
    void visit(string url)
    {
        Tab* newTab=new Tab(url);
        current->next=newTab;
        newTab->prev=current;
        current=newTab;
    }
    
    string back(int steps)
    {
        while(current->prev!=NULL && steps--)
            current=current->prev;
        return current->url;
    }
    
    string forward(int steps)
    {
        while(current->next!=NULL && steps--)
            current=current->next;
        return current->url;
    }
};
