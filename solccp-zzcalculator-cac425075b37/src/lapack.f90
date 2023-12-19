module LAPACK

    implicit none

 private
 public :: syev


contains

SUBROUTINE SYEV(JOBZ, UPLO, N, P, LDP, EVALS)
        INTEGER, INTENT(IN) :: N, LDP
        REAL(KIND=8), INTENT(INOUT), DIMENSION( LDP, N ) :: P
        REAL(KIND=8), INTENT(OUT), DIMENSION(N) :: EVALS
        REAL(KIND=8), ALLOCATABLE, DIMENSION(:) :: WORK

        CHARACTER, INTENT(IN) :: JOBZ, UPLO

        INTEGER :: INFO,LWORK

        LWORK=-1
        ALLOCATE(WORK(1))
        CALL DSYEV(JOBZ, UPLO, N, P, LDP, EVALS, WORK, LWORK, INFO)
        LWORK=INT(WORK(1))
        DEALLOCATE(WORK)
        ALLOCATE(WORK(LWORK))
        CALL DSYEV(JOBZ, UPLO, N, P, LDP, EVALS, WORK, LWORK, INFO)
        DEALLOCATE(WORK)

END SUBROUTINE


end module