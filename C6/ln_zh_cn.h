#pragma once

// 中文语言
#define program_title	"#===================== 病人看病模拟程序 =====================#"
#define program_tline	"#===========================================================#"

#define menu_title_1	"1：排队"
#define menu_desct_1	"\t——输入排队病人的就诊卡号，加入到病人排队的队列中。"
#define menu_title_2	"2：就诊"
#define menu_desct_2	"\t——病人排队队列中最前面的病人就诊，并将其中队列中删除。"
#define menu_title_3	"3：查看排队"
#define menu_desct_3	"\t——从队首到队尾输出所有的排队病人的就诊卡号。"
#define menu_title_4	"4：不再排队"
#define menu_desct_4	"\t——余下的依次就诊从队首到队尾输出所有的排队病人的就诊卡号，看完病后，退出运行。"
#define menu_title_5	"5：下班"
#define menu_desct_5	"\t——退出运行。"

#define inqueue_prompt	"请输入你的就诊卡号："
#define inqueue_invcar	"无效卡号！"
#define inqueue_exist	"卡号 %d 已经在队列中，无需重复排队！"
#define inqueue_in		"卡号 %d 入队成功！"
#define inqueue_fail	"入队失败！"

#define diqueue_empty	"当前没有人在排队！"
#define diqueue_queue	"当前排队："

#define poqueue_out		"就诊的病人是：%d"
#define poqueue_empty	"当前没有病人排队！"

#define unqueue_empty	"当前没有人在排队！"

#define option_plane	"大屏显示"
#define option_select	"请输入你的选择："
#define option_end		"就诊结束！按回车键退出"
#define option_exit		"程序退出！"
#define option_error	"输入错误，请重新输入！"
#define option_continue	"^_^ 按下键回车继续操作..."
