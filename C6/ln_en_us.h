#pragma once

// English language
#define program_title	"#===================== Patient Medical Simulation Program =====================#"
#define program_tline	"#===========================================================#"

#define menu_title_1	"1: Queue"
#define menu_desct_1	"\t！！Enter the medical card number of the patient to be queued, and add it to the patient queue."
#define menu_title_2	"2: Consultation"
#define menu_desct_2	"\t！！The patient at the front of the queue is treated, and then removed from the queue."
#define menu_title_3	"3: View Queue"
#define menu_desct_3	"\t！！Output the medical card numbers of all patients in the queue from the front to the back."
#define menu_title_4	"4: No Longer Queue"
#define menu_desct_4	"\t！！Output the medical card numbers of all patients in the queue from the front to the back one by one, and then exit after treatment."
#define menu_title_5	"5: Off Work"
#define menu_desct_5	"\t！！Exit the program."

#define inqueue_prompt	"Please enter your medical card number:"
#define inqueue_invcar	"Invalid card number!"
#define inqueue_exist	"Card number %d is already in the queue, no need to queue again!"
#define inqueue_in		"Card number %d has been successfully enqueued!"
#define inqueue_fail	"Enqueue failed!"

#define diqueue_empty	"No one is currently in the queue!"
#define diqueue_queue	"Current queue:"

#define poqueue_out		"The patient being treated is: %d"
#define poqueue_empty	"No patients are currently in the queue!"

#define unqueue_empty	"No one is currently in the queue!"

#define option_plane	"Display on screen"
#define option_select	"Please enter your choice:"
#define option_end		"Consultation ended! Press Enter to exit"
#define option_exit		"Program exited!"
#define option_error	"Invalid input, please try again!"
#define option_continue "^_^ Press Enter to continue..."
