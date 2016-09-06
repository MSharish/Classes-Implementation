#include <iostream>

using namespace std;

class node{
	
   private: int data;
   public: node * next;

   public:
  	
  	  node ( int num){
  		
  		data = num;
  		
  	}
  	int get_data(){
  		
  		return data;
  	}	
	
	
};

class LinkedLists{
	
	private: node * FIRST;
	         int no_of_elements;
	
	public: LinkedLists(){
		
		    FIRST = NULL;
			no_of_elements = 0;
	
	}
	
	       void insert_beg(int data){
		       int num = data;
		       node * new_node = new node(num);
		       if ( FIRST == NULL){
			         FIRST = new_node;
			         new_node->next = NULL;
			         no_of_elements++;
		
		        }
		       else{
			       new_node->next = FIRST;
			       FIRST = new_node;
			       no_of_elements++;
		
		        }      
		    
		
	        }
       // end of insert_beginning function

       void insert_end(int data){
	        
	        int iterator = 0;
	        node * temp = FIRST;
	        node * new_node = new node(data);
	      
	         if ( no_of_elements == 0){
		         
		           FIRST = new_node;
		           new_node->next = NULL;
		           no_of_elements++;
		
	         }
	         else{
		
		        while ( temp->next != NULL)
		             temp = temp->next;
		        temp->next = new_node;
		        new_node->next = NULL;
		        no_of_elements++;
	    
             }

      }
      // end of insert_end function
   
          int print_no_elements(){
	
	           return no_of_elements;
          }

      // printing the elements

      void display(){
	
	     node * temp = FIRST;
	     int iterator = 0;
	
	    if ( no_of_elements == 0)
           cout<<"List is empty\n";
        else{
	    while (temp != NULL){
		  
		   cout<<temp->get_data();
		   cout<<"\n";
		   temp = temp->next;
		
	      }
	 
      }
    }

  // inssert at the given position 
  void insert_position( int pos, int data){
    
    int iterator = 0;
    node * temp = FIRST;
		node * new_node = new node(data);
    
    if ( no_of_elements == 0){
      
         insert_beg(data);
    }
    else{
      
        if ( pos == 1)
              insert_beg(data);
         else if ( pos == 2){
          
             new_node->next = temp->next;
             temp->next= new_node;
             no_of_elements++;
          
        }
        else  if(pos > 2){
          
          while ( iterator <= pos-1)
             temp = temp->next;
          new_node->next = temp->next;
          temp->next= new_node;
          no_of_elements++;
          
        }  
     } 
      
    }
   // deletion at the beginning 
  
   int delete_beg(){
      
      node * temp = FIRST;
      int value;
       if ( no_of_elements == 0)
          cout<<"List is empty\n";
       
       else{
        
          FIRST = FIRST->next;
          value = temp->get_data();
          delete temp;
          no_of_elements--;
          return value;

        
       }
      
    }
    
   int delete_end(){
    node * temp = FIRST;
    node * current;
    int value;
    int iterator= 0;
    
    if ( no_of_elements == 0){
       cout<<"List is empty\n";
       value = 0;
      
    }
    else if(no_of_elements == 1){
      
       value = FIRST->get_data();
       delete temp;
       FIRST = NULL;
       no_of_elements--;
      
    }
    else if ( no_of_elements == 2){
      value = temp->next->get_data();
      delete temp->next;
      temp->next = NULL;
      no_of_elements--;
    
      
    }
    else if (no_of_elements > 2){
       
      while ( iterator <= no_of_elements -2){
        
     
        current = temp;
        temp = temp->next;
        iterator++;
      }
      value = temp->get_data();
      delete temp;
      current->next = NULL;
      
       
    }  
    
      return value;
      
  }
  
  // delete at a given position.
  
  int delete_position(int pos){
    
      int iterator = 0, value; 
      node * temp = FIRST, * current;
    
         if ( no_of_elements == 0){
            cout<<"No items present in the list\n";
            value=0;
        }
            
         else{
          
           if ( pos == 1)
              delete_beg();
              
           else if( pos == 2){
            
             current=FIRST->next;
             FIRST->next=current->next;
             value = current->get_data();
             no_of_elements--;
             delete current;
            
           }
           
           else if (pos > 2){
               while ( iterator <= pos-2){
                 
                   current = temp;
                   iterator++;
                   temp = temp->next;
                 
                
                }
                current->next = temp->next;
                value = temp->get_data();
                no_of_elements--;
                delete temp;
               
          }
        }
    
       return value;
    
  }
   
	
};


int main(int argc, char *argv[]) {
	
	 LinkedLists l1,l2;
   int value;
	 l1.insert_position(1,100);
   l1.insert_end(200);
   l1.insert_end(300);
   l1.insert_end(400);
	 l1.display();
	 value = l1.delete_position(4);
   cout<<value<<" is successfully deleted\n";
    l1.display();

	
}