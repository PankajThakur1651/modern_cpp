pipeline {
    agent any
    stages {
        stage("build") {
            steps {
                sh '''
                    pwd
                    mkdir -p build
                    cd build
                    cmake ..
                    make
                '''
            }
        }
        stage("test") {
            steps {
                sh 'ctest --test-dir build --output-on-failure --no-tests=error'
            }
        }

        stage('clean build') {
            steps {
                sh 'rm -rf build'
            }
        }
    }
}
