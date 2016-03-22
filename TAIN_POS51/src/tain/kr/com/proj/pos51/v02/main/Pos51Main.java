/**
 * Copyright 2014, 2015, 2016 TAIN, Inc. all rights reserved.
 *
 * Licensed under the GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.gnu.org/licenses/
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * -----------------------------------------------------------------
 * Copyright 2014, 2015, 2016 TAIN, Inc.
 *
 */
package tain.kr.com.proj.pos51.v02.main;

import java.util.ResourceBundle;

import org.apache.log4j.Logger;

import tain.kr.com.proj.pos51.v02.tools.ReceiveRequest01;
import tain.kr.com.proj.pos51.v02.tools.ReceiveResult02;

/**
 * Code Templates > Comments > Types
 *
 * <PRE>
 *   -. FileName   : Pos51Main.java
 *   -. Package    : tain.kr.com.proj.pos51.v02.main
 *   -. Comment    :
 *   -. Author     : taincokr
 *   -. First Date : 2016. 3. 22. {time}
 * </PRE>
 *
 * @author taincokr
 *
 */
public class Pos51Main {

	private static boolean flag = true;

	private static final Logger log = Logger.getLogger(Pos51Main.class);

	///////////////////////////////////////////////////////////////////////////////////////////////
	
	private String clsName = null;
	
	private String loopWaitSec = null;
	
	private int nLoopWaitSed = -1;
	
	/**
	 * 
	 * Code Templates > Comments > Constructors
	 *
	 * <PRE>
	 *   -. ClassName  : Pos51Main
	 *   -. MethodName : Pos51Main
	 *   -. Comment    :
	 *   -. Author     : taincokr
	 *   -. First Date : 2016. 3. 22. {time}
	 * </PRE>
	 *
	 * @throws Exception
	 */
	private Pos51Main() throws Exception {
		
		if (flag) {
			/*
			 * ResourceBundle
			 */
			this.clsName = this.getClass().getName();
			
			ResourceBundle rb = ResourceBundle.getBundle(this.clsName.replace('.', '/'));
			
			this.loopWaitSec = rb.getString("tain.pos51.main.loop.wait.sec");
		}
		
		if (flag) {
			/*
			 * System.properties
			 */
			this.loopWaitSec = System.getProperty("tain.pos51.main.loop.wait.sec", this.loopWaitSec);
		}
		
		if (flag) {
			/*
			 * change parameters
			 */
			this.nLoopWaitSed = Integer.parseInt(this.loopWaitSec);
		}
	}
	
	public void execute() throws Exception {
		
		if (flag) {
			
			int i = 0;
			while (true) {
				
				if (flag) {
					/*
					 * 01.접수정보 내역    : HANWA -> S_POS_HWPOS000001_yyyymmdd_seq   ->  send_yyyymmddhhmmss.txt -> POST
					 * 
					 */
					Thread thr = new ReceiveRequest01();
					thr.start();
					thr.join();
				}
				
				if (flag) {
					/*
					 * 02.접수 결과        : HANWA <- R_POS_POSHW000002_yyyymmdd_seq   <-  recv_yyyymmddhhmmss.txt <- POST
					 * 
					 */
					Thread thr = new ReceiveResult02();
					thr.start();
					thr.join();
				}
				
				if (flag) {
					/*
					 * 03.배달 결과        : HANWA <- R_POS_POSHW000003_yyyymmdd_seq   <- delv_yyyymmddhhmmss.txt <- POST
					 * 
					 */
					Thread thr = new ReceiveRequest01();
					thr.start();
					thr.join();
				}
				
				/*
				 * loop waiting sleep
				 */
				if (flag) try { Thread.sleep(1000 * this.nLoopWaitSed); } catch (InterruptedException e) {}
				
				i = ++i % 100;
			}
		}
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	
	private static Pos51Main instance = null;
	
	public static synchronized Pos51Main getInstance() throws Exception {
		
		if (instance == null) {
			instance = new Pos51Main();
		}
		
		return instance;
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////

	private static void test01(String[] args) throws Exception {
		
		if (flag) {
			Pos51Main.getInstance().execute();
		}
	}
	
	public static void main(String[] args) throws Exception {
		
		if (flag) log.debug(">>>>> " + new Object(){}.getClass().getEnclosingClass().getName());
		
		if (flag) test01(args);
	}
}
