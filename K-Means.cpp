#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<vector>
using namespace std;

int min(int arr[], int maxIndex)
{
	int min = 100;

	for(int i=0;i<maxIndex;i++)
	{
		if(arr[i]<min)
		{
			min = arr[i];
		}
	}
	return min;
}

int indexOf(int number, int arr[], int maxIndex)
{
	int index;

	for(int i=0;i<maxIndex;i++)
	{
		if(number==arr[i])
		{
			index = i;
			break;
		}
	}
	return index;
}

int mean(vector<int> ngrp)
{
	int sum=0;
	for(int i=0;i<ngrp.size();i++)
	{
		sum = sum + ngrp[i];
	}
	return sum/ngrp.size();
}

int show(vector <int> ngrp)
{
	for(int i=0;i<ngrp.size();i++)
	{
		cout<<ngrp[i]<<",";
	}
}

int isEqual(int arr1[],int arr2[],int maxIndex)
{
	for(int i=0;i<maxIndex;i++)
	{
		if(arr1[i]==arr2[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int noofitems;
	int k;
	while(true)
	{
		cout<<"\nEnter n objects: ";
		cin>>noofitems;

		cout<<"\nEnter number of clusters: ";
		cin>>k;

		if(k>noofitems)
		{
			cout<<"\n Number of clusters cannot be greater than number of items";
		}
		else
		{
			break;
		}
	}
	
	int cluster[k];
	int oldcluster[k];
	int objects[noofitems];
	int row[k];

	vector<vector<int> > groups;

	for(int i=0;i<noofitems;i++)
	{
		cout<<endl;
		cout<<"Enter Value ("<<(i+1)<<") :";
		cin>>objects[i];

		if(i<k)
		{
			cluster[i]=objects[i];
		}
	}

	for(int i=0;i<k;i++)
	{
		vector<int> newgroup;
		groups.push_back(newgroup);
	}
	
	int iter = 1;

	do
	{
		for(int i=0;i<noofitems;i++)
		{
			for(int j=0;j<k;j++)
			{
				row[j] = abs(cluster[j] - objects[i]);
			}
			groups[indexOf(min(row,k),row,k)].push_back(objects[i]);
		}
		
		for(int j=0;j<k;j++)
		{
			if(!groups[j].empty())
			{
				oldcluster[j]=cluster[j];
				cluster[j]=mean(groups[j]);
			}
		}

		if(!isEqual(oldcluster,cluster,k))
		{
			for(int i=0;i<k;i++)
			{
				groups[i].clear();
			}
		}
		iter++;
	}while(!isEqual(oldcluster,cluster,k));

	for(int i=0;i<k;i++)
	{
		cout<<"C"<<i+1<<" : \n"<<cluster[i]<<endl;
		show(groups[i]);
	}

	for(int i=0;i<k;i++)
	{
		cout<<" \nGroup"<<i+1<<": \n"<<endl;
		show(groups[i]);
	}
	cout<<"\nNo. of iterations :"<<iter<<endl;
	return 0;
}
