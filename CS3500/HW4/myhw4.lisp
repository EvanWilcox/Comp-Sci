; Evan Wilcox
; CS3500 HW4
; 12/4/19

; (myLast L )
(defun myLast ( L )
  (cond ((eq (cdr L) nil) (car L))
        (t                (myLast (cdr L)))
  )
)

; (myCount X L )
(defun myCount ( X L )
  (cond ((eq nil (car L)) 0)
        ((eq X (car L))   (+ (myCount X (cdr L)) 1) )
        (t                (myCount X (cdr L)))
  )
)

; (myMember X L )
(defun myMember ( X L )
  (cond ((eq nil (car L)) nil) 
        ((eq X (car L))   t)
        (t                (myMember X (cdr L)))
  )
)

; (myPurge L )
(defun myPurge ( L )
  (cond ((eq nil (car L))           nil)
        ((myMember (car L) (cdr L)) (myPurge (cdr L)))
        (t                          (cons (car L) (myPurge (cdr L))))
  )
)

; (myCommon X Y )
(defun myCommon ( X Y )
  (cond((eq nil (car X))     nil)
       ((eq nil (car Y))     nil)
       ((myMember (car X) Y) (cons (car X) (myCommon (cdr X) Y)))
       (t                    (myCommon (cdr X) Y))
  )
)

; (myGen X Y )
(defun myGen ( X Y )
  (cond((>= X Y) X)
        (t        (cons X (myGen (+ X 1) Y)))
  )
)

; (myMap F L )
(defun myMap ( F L )
  (cond((eq nil (cdr L)) (funcall f (car L)))
       (t                (cons (funcall F (car L)) (myMap F (cdr L))))
  )
)

; (myReduce F L )
(defun myReduce ( F L )
  (cond ((eq nil (cdr L)) (car L))
        (t                (myReduce F (cons (funcall F (car L) (car (cdr L))) (cdr (cdr L)))))
  )
)
