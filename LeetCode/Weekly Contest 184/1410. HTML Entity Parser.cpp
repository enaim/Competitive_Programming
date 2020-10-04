class Solution {
public:
    string entityParser(string text) {
        int i,z,n = text.size();
        string temp,tem="";
        for(i=0;i<text.size();i++)
        {
            int f = 0;
            if(i+7<=n)
            {
                temp.clear();
                temp = text.substr(i,7);
                if(temp=="&frasl;")
                {
                    f = 1;
                    tem+="/";
                    i+=6;
                    continue;
                }
            }
            if(i+6<=n)
            {
                temp = text.substr(i,6);
                if(temp=="&quot;")
                {
                    f = 1;
                    tem+="\"";
                    i+=5;
                    continue;
                }
                if(temp=="&apos;")
                {
                    f = 1;
                    tem+="'";
                    i+=5;
                    continue;
                }
            }
            if(i+5<=n)
            {
                temp = text.substr(i,5);
                if(temp=="&amp;")
                {
                    f = 1;
                    tem+="&";
                    i+=4;
                    continue;
                }
            }
            if(i+4<=n)
            {
                temp = text.substr(i,4);
                if(temp=="&gt;")
                {
                    f = 1;
                    tem+=">";
                    i+=3;
                    continue;
                }
                if(temp=="&lt;")
                {
                    f = 1;
                    tem+="<";
                    i+=3;
                    continue;
                }
            }
            tem+=text[i];
        }
        return tem;
    }
};
