
// PsiScaleEditorDlg.h : 头文件
//

#pragma once

#include <memory>
#include "afxwin.h"
#include "afxvslistbox.h"
#include "../PsiCommon/TestManager.h"
#include "QuestionListBox.h"
#include "afxeditbrowsectrl.h"

class PsiScale;
class PsiScaleQuestion;


// CPsiScaleEditorDlg 对话框
class CPsiScaleEditorDlg : public CDialogEx
{
// 构造
public:
	CPsiScaleEditorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PSI_SCALE_EDITOR };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;
	std::shared_ptr<PsiScale> _scale;
	CTestManager _test_manager;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckSameChoice();
	afx_msg void OnBnClickedButtonNew();

	UINT _scale_id;
	CString _scale_name;
	CString _prologue_text;
	BOOL _use_same_choices;
	
	void UpdateUi();

	afx_msg void OnBnClickedButtonAddQuestion();
// 	afx_msg void OnBnClickedButtonAddGroup();
// 	afx_msg void OnBnClickedButtonAddChoice();
// 	afx_msg void OnEnChangeEditQuestion();
	afx_msg void OnLbnSelchangeListQuestions();
	afx_msg void OnEnChangeName();
	afx_msg void OnBnClickedButtonSave();

	CButton _add_question_button;
	CButton _delete_question_button;
	CEdit _scale_id_edit;
	CEdit _scale_name_edit;
	CEdit _prologue_text_edit;
	CButton _shared_choices_checkbox;
	CButton _new_scale_table_button;
	CButton _save_scale_button;
	CButton _exit_button;

	CQuestionListBox _question_list;
	CVSListBox _group_list;
	CVSListBox _choice_list;
	CMFCEditBrowseCtrl _working_folder_edit;
	CComboBox _scales_combo;
	afx_msg void OnEnChangeEditWorkingFolder();
	CString _working_folder;
};
