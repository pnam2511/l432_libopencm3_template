Uncrustify is an autoformatter that will clean our code and ensure we are
following our coding standard as much as possible.

Use in AMS project :
0. ALWAYS COMMIT YOUR LATEST CHANGES BEFORE RUNNING THE AUTOFORMATTER.
1. Highlight the file or directory to run on.
2. Go to Run > External Tools Configurations.
3. Select Autoformat.
4. Click Run.
5. Scan through the formatted code and look for poorly formatted comments.  When a 
   comment exceeds the 120 character limit, Uncrustify will wrap the comment, but
   characters from the following line need to be reformatted manually.


TODO                                : Identify rules Uncrustify cannot check here.

Syntax                              :
> call_Uncrustify dirname extension

           Examples                 :
To run on all C files               :
> call_Uncrustify C                 : \ path_to_folder c

To run on all header files          :
> call_Uncrustify C                 : \ path_to_folder h

           Maintenance              :
To make changes to this             :
1. Download UniversalIndentGUI from : http : //universalindent.sourceforge.net/
2. Import call_Uncrustify.cfg.Go to Indenter > Load Indenter Config File (Alt + O)
3. Make changes.
4. Save indenter configuration.Go to Indenter > Save Indenter Config File .
