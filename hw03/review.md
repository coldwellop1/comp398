Style Guide Evaluation

	-- Names and Order of Includes --
			Your code appears as this:
					#include "stdafx.h"
					#include "Node.h"
					#include <iostream>
					#include <fstream>
					#include <cstdlib>

				It should be:
					#include "stdafx.h"
					#include <iostream>
					#include <fstream>
					#include <cstdlib>
					#include "Node.h"
					
		-- Access Control -- 
			You did not make any of your node class's members private.  next_ and data_member_ should both be private.
			
		-- Reference Arguments -- 
			Your variable 'selection' is passed by reference in your main function and the style guide states "within function parameter lists all references must be const"
			
		-- File Names --
			Your file names should be in all lowercase letters and use _ or - to separate words. Ex. README.txt should be read_me.txt and diseaseNcause.txt should be disease_n_cause.txt
			
		Other than that, your code looks pretty good, I'd just add more comments that explain what it is that's going on.
			

Code Evaluation

	Errors I ran into when running the program: 
		Selected "2. View all diseases in the database starting from a specified letter", entered "R", program repeatedly printed R's to the console until I force quit it.
		
	You are missing the plaintext copy of the output of your code.


