; Listing generated by Microsoft (R) Optimizing Compiler Version 19.29.30133.0 

	TITLE	E:\Desktop\Raven\Raven1\Buckland_Chapter7 to 10_Raven\Debug\Goal_Wander.obj
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMTD
INCLUDELIB OLDNAMES

CONST	SEGMENT
?colors@@3QBKB DD 0ffH					; colors
	DD	0ff0000H
	DD	0ff00H
	DD	00H
	DD	0c8c8ffH
	DD	0c8c8c8H
	DD	0ffffH
	DD	0aaffH
	DD	0aa00ffH
	DD	05a85H
	DD	0ffffffH
	DD	06400H
	DD	0ffff00H
	DD	0c8c8c8H
	DD	0e6e6ffH
$SG167155 DB	'invalid argument', 00H
	ORG $+3
$SG167156 DB	'%s', 00H
	ORG $+5
$SG167157 DB	'C:\Program Files (x86)\Microsoft Visual Studio\2019\Comm'
	DB	'unity\VC\Tools\MSVC\14.29.30133\include\xmemory', 00H
$SG167158 DB	'C', 00H, ':', 00H, '\', 00H, 'P', 00H, 'r', 00H, 'o', 00H
	DB	'g', 00H, 'r', 00H, 'a', 00H, 'm', 00H, ' ', 00H, 'F', 00H, 'i'
	DB	00H, 'l', 00H, 'e', 00H, 's', 00H, ' ', 00H, '(', 00H, 'x', 00H
	DB	'8', 00H, '6', 00H, ')', 00H, '\', 00H, 'M', 00H, 'i', 00H, 'c'
	DB	00H, 'r', 00H, 'o', 00H, 's', 00H, 'o', 00H, 'f', 00H, 't', 00H
	DB	' ', 00H, 'V', 00H, 'i', 00H, 's', 00H, 'u', 00H, 'a', 00H, 'l'
	DB	00H, ' ', 00H, 'S', 00H, 't', 00H, 'u', 00H, 'd', 00H, 'i', 00H
	DB	'o', 00H, '\', 00H, '2', 00H, '0', 00H, '1', 00H, '9', 00H, '\'
	DB	00H, 'C', 00H, 'o', 00H, 'm', 00H, 'm', 00H, 'u', 00H, 'n', 00H
	DB	'i', 00H, 't', 00H, 'y', 00H, '\', 00H, 'V', 00H, 'C', 00H, '\'
	DB	00H, 'T', 00H, 'o', 00H, 'o', 00H, 'l', 00H, 's', 00H, '\', 00H
	DB	'M', 00H, 'S', 00H, 'V', 00H, 'C', 00H, '\', 00H, '1', 00H, '4'
	DB	00H, '.', 00H, '2', 00H, '9', 00H, '.', 00H, '3', 00H, '0', 00H
	DB	'1', 00H, '3', 00H, '3', 00H, '\', 00H, 'i', 00H, 'n', 00H, 'c'
	DB	00H, 'l', 00H, 'u', 00H, 'd', 00H, 'e', 00H, '\', 00H, 'x', 00H
	DB	'm', 00H, 'e', 00H, 'm', 00H, 'o', 00H, 'r', 00H, 'y', 00H, 00H
	DB	00H
$SG167159 DB	's', 00H, 't', 00H, 'd', 00H, ':', 00H, ':', 00H, '_', 00H
	DB	'A', 00H, 'l', 00H, 'l', 00H, 'o', 00H, 'c', 00H, 'a', 00H, 't'
	DB	00H, 'e', 00H, '_', 00H, 'm', 00H, 'a', 00H, 'n', 00H, 'u', 00H
	DB	'a', 00H, 'l', 00H, 'l', 00H, 'y', 00H, '_', 00H, 'v', 00H, 'e'
	DB	00H, 'c', 00H, 't', 00H, 'o', 00H, 'r', 00H, '_', 00H, 'a', 00H
	DB	'l', 00H, 'i', 00H, 'g', 00H, 'n', 00H, 'e', 00H, 'd', 00H, 00H
	DB	00H
	ORG $+2
$SG167160 DB	'"', 00H, 'i', 00H, 'n', 00H, 'v', 00H, 'a', 00H, 'l', 00H
	DB	'i', 00H, 'd', 00H, ' ', 00H, 'a', 00H, 'r', 00H, 'g', 00H, 'u'
	DB	00H, 'm', 00H, 'e', 00H, 'n', 00H, 't', 00H, '"', 00H, 00H, 00H
CONST	ENDS
PUBLIC	?__empty_global_delete@@YAXPAX@Z		; __empty_global_delete
PUBLIC	?__empty_global_delete@@YAXPAXI@Z		; __empty_global_delete
PUBLIC	?GetSteering@Raven_Bot@@QAEQAVRaven_Steering@@XZ ; Raven_Bot::GetSteering
PUBLIC	?ActivateIfInactive@?$Goal@VRaven_Bot@@@@IAEXXZ	; Goal<Raven_Bot>::ActivateIfInactive
PUBLIC	?isInactive@?$Goal@VRaven_Bot@@@@QBE_NXZ	; Goal<Raven_Bot>::isInactive
PUBLIC	?Activate@Goal_Wander@@UAEXXZ			; Goal_Wander::Activate
PUBLIC	?Process@Goal_Wander@@UAEHXZ			; Goal_Wander::Process
PUBLIC	?Terminate@Goal_Wander@@UAEXXZ			; Goal_Wander::Terminate
PUBLIC	?On@Raven_Steering@@AAE_NW4behavior_type@1@@Z	; Raven_Steering::On
PUBLIC	?WanderOn@Raven_Steering@@QAEXXZ		; Raven_Steering::WanderOn
PUBLIC	?WanderOff@Raven_Steering@@QAEXXZ		; Raven_Steering::WanderOff
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
; Function compile flags: /Odtp /RTCsu
; File E:\Desktop\Raven\Raven1\Buckland_Chapter7 to 10_Raven\Raven_SteeringBehaviors.h
;	COMDAT ?WanderOff@Raven_Steering@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4						; size = 4
?WanderOff@Raven_Steering@@QAEXXZ PROC			; Raven_Steering::WanderOff, COMDAT
; _this$ = ecx

; 214  :   void WanderOff(){if(On(wander)) m_iFlags ^=wander;}

	push	ebp
	mov	ebp, esp
	push	ecx
	mov	DWORD PTR [ebp-4], -858993460		; ccccccccH
	mov	DWORD PTR _this$[ebp], ecx
	push	16					; 00000010H
	mov	ecx, DWORD PTR _this$[ebp]
	call	?On@Raven_Steering@@AAE_NW4behavior_type@1@@Z ; Raven_Steering::On
	movzx	eax, al
	test	eax, eax
	je	SHORT $LN1@WanderOff
	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx+168]
	xor	edx, 16					; 00000010H
	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+168], edx
$LN1@WanderOff:
	add	esp, 4
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?WanderOff@Raven_Steering@@QAEXXZ ENDP			; Raven_Steering::WanderOff
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu
; File E:\Desktop\Raven\Raven1\Buckland_Chapter7 to 10_Raven\Raven_SteeringBehaviors.h
;	COMDAT ?WanderOn@Raven_Steering@@QAEXXZ
_TEXT	SEGMENT
_this$ = -4						; size = 4
?WanderOn@Raven_Steering@@QAEXXZ PROC			; Raven_Steering::WanderOn, COMDAT
; _this$ = ecx

; 208  :   void WanderOn(){m_iFlags |= wander;}

	push	ebp
	mov	ebp, esp
	push	ecx
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+168]
	or	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _this$[ebp]
	mov	DWORD PTR [edx+168], ecx
	mov	esp, ebp
	pop	ebp
	ret	0
?WanderOn@Raven_Steering@@QAEXXZ ENDP			; Raven_Steering::WanderOn
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu
; File E:\Desktop\Raven\Raven1\Buckland_Chapter7 to 10_Raven\Raven_SteeringBehaviors.h
;	COMDAT ?On@Raven_Steering@@AAE_NW4behavior_type@1@@Z
_TEXT	SEGMENT
tv67 = -8						; size = 4
_this$ = -4						; size = 4
_bt$ = 8						; size = 4
?On@Raven_Steering@@AAE_NW4behavior_type@1@@Z PROC	; Raven_Steering::On, COMDAT
; _this$ = ecx

; 131  :   bool      On(behavior_type bt){return (m_iFlags & bt) == bt;}

	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+168]
	and	ecx, DWORD PTR _bt$[ebp]
	cmp	ecx, DWORD PTR _bt$[ebp]
	jne	SHORT $LN3@On
	mov	DWORD PTR tv67[ebp], 1
	jmp	SHORT $LN4@On
$LN3@On:
	mov	DWORD PTR tv67[ebp], 0
$LN4@On:
	mov	al, BYTE PTR tv67[ebp]
	mov	esp, ebp
	pop	ebp
	ret	4
?On@Raven_Steering@@AAE_NW4behavior_type@1@@Z ENDP	; Raven_Steering::On
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu
; File E:\Desktop\Raven\Raven1\Buckland_Chapter7 to 10_Raven\goals\Goal_Wander.cpp
_TEXT	SEGMENT
_this$ = -4						; size = 4
?Terminate@Goal_Wander@@UAEXXZ PROC			; Goal_Wander::Terminate
; _this$ = ecx

; 31   : {

	push	ebp
	mov	ebp, esp
	push	ecx
	mov	DWORD PTR [ebp-4], -858993460		; ccccccccH
	mov	DWORD PTR _this$[ebp], ecx

; 32   :   m_pOwner->GetSteering()->WanderOff();

	mov	eax, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	call	?GetSteering@Raven_Bot@@QAEQAVRaven_Steering@@XZ ; Raven_Bot::GetSteering
	mov	ecx, eax
	call	?WanderOff@Raven_Steering@@QAEXXZ	; Raven_Steering::WanderOff

; 33   : }

	add	esp, 4
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?Terminate@Goal_Wander@@UAEXXZ ENDP			; Goal_Wander::Terminate
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu
; File E:\Desktop\Raven\Raven1\Buckland_Chapter7 to 10_Raven\goals\Goal_Wander.cpp
_TEXT	SEGMENT
_this$ = -4						; size = 4
?Process@Goal_Wander@@UAEHXZ PROC			; Goal_Wander::Process
; _this$ = ecx

; 21   : {

	push	ebp
	mov	ebp, esp
	push	ecx
	mov	DWORD PTR [ebp-4], -858993460		; ccccccccH
	mov	DWORD PTR _this$[ebp], ecx

; 22   :   //if status is inactive, call Activate()
; 23   :   ActivateIfInactive();

	mov	ecx, DWORD PTR _this$[ebp]
	call	?ActivateIfInactive@?$Goal@VRaven_Bot@@@@IAEXXZ ; Goal<Raven_Bot>::ActivateIfInactive

; 24   : 
; 25   :   return m_iStatus;

	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+12]

; 26   : }

	add	esp, 4
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?Process@Goal_Wander@@UAEHXZ ENDP			; Goal_Wander::Process
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu
; File E:\Desktop\Raven\Raven1\Buckland_Chapter7 to 10_Raven\goals\Goal_Wander.cpp
_TEXT	SEGMENT
_this$ = -4						; size = 4
?Activate@Goal_Wander@@UAEXXZ PROC			; Goal_Wander::Activate
; _this$ = ecx

; 12   : {

	push	ebp
	mov	ebp, esp
	push	ecx
	mov	DWORD PTR [ebp-4], -858993460		; ccccccccH
	mov	DWORD PTR _this$[ebp], ecx

; 13   :   m_iStatus = active;

	mov	eax, DWORD PTR _this$[ebp]
	mov	DWORD PTR [eax+12], 0

; 14   : 
; 15   :   m_pOwner->GetSteering()->WanderOn();

	mov	ecx, DWORD PTR _this$[ebp]
	mov	ecx, DWORD PTR [ecx+8]
	call	?GetSteering@Raven_Bot@@QAEQAVRaven_Steering@@XZ ; Raven_Bot::GetSteering
	mov	ecx, eax
	call	?WanderOn@Raven_Steering@@QAEXXZ	; Raven_Steering::WanderOn

; 16   : }

	add	esp, 4
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?Activate@Goal_Wander@@UAEXXZ ENDP			; Goal_Wander::Activate
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu
; File E:\Desktop\Raven\Raven1\Common\Goals\Goal.h
;	COMDAT ?isInactive@?$Goal@VRaven_Bot@@@@QBE_NXZ
_TEXT	SEGMENT
tv66 = -8						; size = 4
_this$ = -4						; size = 4
?isInactive@?$Goal@VRaven_Bot@@@@QBE_NXZ PROC		; Goal<Raven_Bot>::isInactive, COMDAT
; _this$ = ecx

; 82   :   bool         isInactive()const{return m_iStatus == inactive;}

	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _this$[ebp]
	cmp	DWORD PTR [eax+12], 1
	jne	SHORT $LN3@isInactive
	mov	DWORD PTR tv66[ebp], 1
	jmp	SHORT $LN4@isInactive
$LN3@isInactive:
	mov	DWORD PTR tv66[ebp], 0
$LN4@isInactive:
	mov	al, BYTE PTR tv66[ebp]
	mov	esp, ebp
	pop	ebp
	ret	0
?isInactive@?$Goal@VRaven_Bot@@@@QBE_NXZ ENDP		; Goal<Raven_Bot>::isInactive
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu
; File E:\Desktop\Raven\Raven1\Common\Goals\Goal.h
;	COMDAT ?ActivateIfInactive@?$Goal@VRaven_Bot@@@@IAEXXZ
_TEXT	SEGMENT
_this$ = -4						; size = 4
?ActivateIfInactive@?$Goal@VRaven_Bot@@@@IAEXXZ PROC	; Goal<Raven_Bot>::ActivateIfInactive, COMDAT
; _this$ = ecx

; 114  : {

	push	ebp
	mov	ebp, esp
	push	ecx
	push	esi
	mov	DWORD PTR [ebp-4], -858993460		; ccccccccH
	mov	DWORD PTR _this$[ebp], ecx

; 115  :   if (isInactive())

	mov	ecx, DWORD PTR _this$[ebp]
	call	?isInactive@?$Goal@VRaven_Bot@@@@QBE_NXZ ; Goal<Raven_Bot>::isInactive
	movzx	eax, al
	test	eax, eax
	je	SHORT $LN1@ActivateIf

; 116  :   {
; 117  :     Activate();   

	mov	ecx, DWORD PTR _this$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	esi, esp
	mov	ecx, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [edx+4]
	call	eax
	cmp	esi, esp
	call	__RTC_CheckEsp
$LN1@ActivateIf:

; 118  :   }
; 119  : }

	pop	esi
	add	esp, 4
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
?ActivateIfInactive@?$Goal@VRaven_Bot@@@@IAEXXZ ENDP	; Goal<Raven_Bot>::ActivateIfInactive
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu
; File E:\Desktop\Raven\Raven1\Buckland_Chapter7 to 10_Raven\Raven_Bot.h
;	COMDAT ?GetSteering@Raven_Bot@@QAEQAVRaven_Steering@@XZ
_TEXT	SEGMENT
_this$ = -4						; size = 4
?GetSteering@Raven_Bot@@QAEQAVRaven_Steering@@XZ PROC	; Raven_Bot::GetSteering, COMDAT
; _this$ = ecx

; 204  :   Raven_Steering* const              GetSteering(){return m_pSteering;}

	push	ebp
	mov	ebp, esp
	push	ecx
	mov	DWORD PTR _this$[ebp], ecx
	mov	eax, DWORD PTR _this$[ebp]
	mov	eax, DWORD PTR [eax+160]
	mov	esp, ebp
	pop	ebp
	ret	0
?GetSteering@Raven_Bot@@QAEQAVRaven_Steering@@XZ ENDP	; Raven_Bot::GetSteering
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu
; File E:\Desktop\Raven\Raven1\Buckland_Chapter7 to 10_Raven\goals\Goal_Wander.cpp
;	COMDAT ?__empty_global_delete@@YAXPAXI@Z
_TEXT	SEGMENT
___formal$ = 8						; size = 4
___formal$ = 12						; size = 4
?__empty_global_delete@@YAXPAXI@Z PROC			; __empty_global_delete, COMDAT

	push	ebp
	mov	ebp, esp
	pop	ebp
	ret	0
?__empty_global_delete@@YAXPAXI@Z ENDP			; __empty_global_delete
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu
; File E:\Desktop\Raven\Raven1\Buckland_Chapter7 to 10_Raven\goals\Goal_Wander.cpp
;	COMDAT ?__empty_global_delete@@YAXPAX@Z
_TEXT	SEGMENT
___formal$ = 8						; size = 4
?__empty_global_delete@@YAXPAX@Z PROC			; __empty_global_delete, COMDAT

	push	ebp
	mov	ebp, esp
	pop	ebp
	ret	0
?__empty_global_delete@@YAXPAX@Z ENDP			; __empty_global_delete
_TEXT	ENDS
END