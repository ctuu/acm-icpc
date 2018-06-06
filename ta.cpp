class WordAndPhraseDiv1
{
  public:
    int findNumberOfPhrases(string w)
    {
        int si = w.size();
        int ud[1003] = {0};
        res int ct = 0, u = -1, v = -1;
        for (int i = 0; i < si; ++i)
        {
            if (w[i] == '_')
            {
                ++ct;
                v = u == -1 ? -1 : i;
                u = u == -1 ? i : u;
            }
            else
            {
                ct = u == 0 ? ct - 1 : ct;
                ct = v == si - 1 ? ct - 1 : ct;
                ud[ct]++;
                u = v = -1;
                ct = 0;
            }
        }
    }
};

a___b
a.__b  1*2
a_._b  1*1
a__.b  2*1
a._.b 


__
._
_.


a____b
a.___b 1 * 3
    .___
    ._._
    .__.    

a_.__b 1 * 2
    _.__
    _._.

a__._b 2 * 1
    __._
    ._._
a___.b 3 * 1
    ___.
    .__.
    _._.

    ____
    .___
    ._._
    .__.
    _.__
    _._.
    __._
    ___.


_____
.____  1 * 5
._.__
.__._
.___.
._._.
_.___ 1 * 3
_._._
_.__.
__.__ 2 * 2
__._.
___._ 3 * 1
____. 5 * 1





