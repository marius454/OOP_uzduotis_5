# OOP_uzduotis_5

## "Cool dalikėliai"

1. ispunct, tolower

```c++
for (size_t i = 0; i < str.size(); ++i)
	{
		if (ispunct(str[i]) && str[i]!= '\'') 
		{
			str.erase(i, 1);
			--i;
		}
		else if (isupper(str[i])) 
		{
			str[i] = tolower(str[i]);
			
		}
	}
```

## Programos paskirtis

  Naudojant std::map konteinerį išimti visus pasikartojančius žodžius parašyti kiek kartu jie pasikartoja ir kuriose eilutėse jie yra.
