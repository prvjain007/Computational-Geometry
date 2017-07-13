int main()
{
    int n;//! An integer.
    /*! Number of Points */
    cout<<"This program loads convex hull co-ordinates in .ch file"<<endl;
    cout<<"Enter the number of Points- ";
    cin>>n;
    Point p[n];
    readWrite rs;
    Point b[n];
    float f, ff;
    ifstream theFile("read.txt");
    int i=0, in;
    while(theFile >> f  >> ff >> in)
    {
        p[i].setX(f);
        p[i].setY(ff);
        p[i].setId(i);
        i++;
    }
    jarvis jj;
    int j;
    j=jj.jarvi(p,n,b);
    Point c[n-j];
    int ll=0,r=0;
    for(int i=0;i<n;i++)
    {
        r=0;
        for(int k=0;k<j;k++)
        {
            if(b[k].getId()==i)
                {
                    r=1;
                    break;
                }
        }
        if(r==0)
        {
            c[ll]=p[i];
            ll++;
        }
    }
    compare cc;
    cc.sortX(c,ll);
    int indi=0,l=0,m=0;
    Point d[n],e[n];
    for(int i=0;i<j;i++)
    {
        if(indi==0)
        {
            d[l]=b[i];
            d[l].setD(false);
            l++;
        }

        if(i>0 && b[i].getX()<b[i-1].getX() && indi==0)
        {
            l--;
            for(int k=n-j-1;k>=0;k--)
            {

                d[l]=c[k];
                d[l].setD(true);
                l++;
            }


            e[m]=b[i-1];
            e[m].setD(false);
            m++;
            indi=1;
        }
        if(indi==1)
        {
            e[m]=b[i];
            e[m].setD(true);
            m++;
        }

    }


    e[m]=b[0];
    e[m].setD(false);
    m++;
    for(int i=0;i<n-j;i++)
    {
        e[m]=c[i];
        e[m].setD(false);
        m++;
    }
    readWrite w;
    w.write(p,n,j,b);
    w.writee(p,n,d,l,e,m);
    cc.sortX(d,l);
    cc.sortX(e,m);
    d[0].setD(d[1].getD());
    e[0].setD(e[1].getD());

    queue<Point> st;
    st.push(d[1]);
    Point rr,re;
    for(int i=1;i<l;i++)
    {
        rr=d[i+1];
        re=d[i];
        if(re.getD()!=rr.getD())
        {
            while(!st.empty())
            {
                cout<<"add edge to"<<re.getX()<<" " << re.getY() << " from " << rr.getX() << " " << rr.getY()<<endl;
                st.pop();
            }


            st.push(re);
        }
        else
        {
            st.push(re);
        }
    }
    //Polyt p(d,l);
    //Polyt pp(e,m);
    w.writeee(p,n,d,l,e,m);
    return 0;
}
