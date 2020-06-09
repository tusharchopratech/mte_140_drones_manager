#include "lab2_drones_manager.hpp"
#include <iostream>
using namespace std;

// TODO: Implement all of the listed functions below
// See the assignment specifications and the header file for details
// Your code needs to pass at least all of the provided test cases

DronesManager::DronesManager() {
	size=0;
	first=NULL;
	last=NULL;
	
}

DronesManager::~DronesManager() {
	
	while(first){
		DroneRecord* tmp = first;
		first=first->next;
		delete tmp; 
	}
	first=NULL;
	last=NULL;
	size=0;
	
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	return (lhs.droneID == rhs.droneID) && (lhs.range == rhs.range) && (lhs.yearBought == rhs.yearBought) && (lhs.droneType == rhs.droneType) && (lhs.manufacturer == rhs.manufacturer) 
	&& (lhs.description == rhs.description) && (lhs.batteryType == rhs.batteryType);
}

unsigned int DronesManager::get_size() const {
	return size;
}

bool DronesManager::empty() const {
	return first==NULL;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	
	if (first==NULL){
		return DroneRecord(0);
	}
	
	DroneRecord tmp,*cur;
	if(index > get_size()){
		tmp = *last;
		return tmp;
	}

	int i=1;
	cur=first;
	while(i<=index && cur->next)
	{
		cur=cur->next;
		i++;
	}
	tmp = *cur;
	return tmp;
}

int DronesManager::search(DroneRecord value) const {
	if (first==NULL){
		return -1;
	}
	int i=0;
	DroneRecord *cur;
	cur=first;
	while(cur!=NULL){
		
		if((*cur)==value){
			break;
		}
		cur=cur->next;
		i++;
	}
	return i;
}

void DronesManager::print() const {
	DroneRecord *cur;
	cur=first;
	while(cur){
		cout<<cur->droneID<<" ";
		cur=cur->next;
	}
	cout<<endl;
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	if (first==NULL){
		return false;
	}
	
	if(index > get_size()){
		return false;
	}

	DroneRecord *cur;
	int i=1;
	cur=first;
	while(i<=index && cur->next)
	{
		cur=cur->next;
		i++;
	}
	cout<<"at index "<<index<<" value "<<value.droneID<<endl;
	print();
	DroneRecord* tmp = new DroneRecord(value);
	
	tmp->prev=cur->prev;
	tmp->next=cur;
	cur->prev=tmp;
	
	size++;
	print();
	return true;
}

bool DronesManager::insert_front(DroneRecord value) {
	DroneRecord* tmp = new DroneRecord(value);
	if(get_size()==0){
		first= tmp;
		last = tmp;
	}else{
		tmp->next=first;
		first->prev=tmp;
		tmp->prev=NULL;
		first=tmp;
	}
	size++;
	return true;
}

bool DronesManager::insert_back(DroneRecord value) {
	DroneRecord* tmp = new DroneRecord(value);
	if(get_size()==0){
		first= tmp;
		last=tmp;
	}else{
		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
		last = tmp;
	}
	size++;
	return true;
}

bool DronesManager::remove(unsigned int index) {
	return false;
}

bool DronesManager::remove_front() {
	if(first == NULL){
		return false;
	}else if(first->next==NULL){
		delete first;
		first=NULL;
		last=NULL;
	}else{	
		DroneRecord* tmp = first;
		first=first->next;
		delete tmp;
	}
	size--;
	
	return true;
}

bool DronesManager::remove_back() {
	if(first == NULL){
		return false;
	}else if(first->next==NULL){
		delete first;
		first=NULL;
		last=NULL;
	}else{	
		DroneRecord* tmp = last;
		last=last->prev;
		delete tmp;
	}
	size--;
	return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	
	if (first==NULL){
		return false;
	}
	
	if(index > get_size()){
		return false;
	}

	DroneRecord *cur;
	int i=1;
	cur=first;
	while(i<=index && cur->next)
	{
		cur=cur->next;
		i++;
	}
	
	DroneRecord* tmp = new DroneRecord(value);
	tmp->next=cur->next;
	tmp->prev=cur->prev;
	*cur=*tmp;
	return true;
}

bool DronesManager::reverse_list() {
//	print();
	DroneRecord *cur, *tmp;
	
	last=first;
	
	cur=first;
	while(cur){		
		swap(cur->next, cur->prev);
		first=cur;
		cur=cur->prev;
	}
//	print();
//	
//	cout<<first->droneID<<endl;
//	cout<<last->droneID<<endl;
	return true;
}
