const jwt=require("jsonwebtoken");
const User=require("../Models/userModel")

exports.Register = async(req,res)=>{
    try{
        if(req.body.password!=req.body.ConfirmPassword){
            return res.send("password does not match");
        }

        const user=await User.create({
             Name:req.body.Name,
             email:req.body.email,
             password:req.body.password ,
             ConfirmPassword:req.body.ConfirmPassword,
             Role:req.body.Role})

        res.send("Account created successfully");
        }
        catch(e){
            console.log(e)
        }
}

exports.login = async(req,res)=>{
            try{
                const user = await User.findOne({email:req.body.email}).select("+password") //select is used to delibertely get password
                 console.log(user)
                if(user!=null){
                    if(user.password!=req.body.password){
                        res.send('wrong password')
                    }else{
                        const token = user.getJWTToken()
                        res.cookie('token',token).json({
                            success:true,
                            user
                        })
                        // res.send("welcome "+user.name)
                    }
                }else{
                    return res.send('user not found')

                }
            }catch(e){
                console.log(e)
            }
        }


exports.logout =async(req,res)=>{
    try{
        res.clearCookie("token").json({message:"logout"}) 
    }
    catch(e){
        // console.log(e)
        
    }
}

exports.updateDetails=async (req,res)=>{
    try{
        await User.findByIdAndUpdate({_id:req.params.__id},{Name:req.body.Name,email:req.body.email}) ;
                                    //({which id to update taken from params},{what to update})
        res.json({message:"User details updated"});
        // res.json(user);

    }
    catch(e){
        console.log(e);
    }
}

exports.updatePassword=async (req,res)=>{
    try{
        await User.findByIdAndUpdate(req.params.__id,{password:req.body.password}) ;
                                    //(which id to update taken from params,{what to update})
        res.json({message:"password updated"});
        // res.json(user);

    }
    catch(e){
        console.log(e);
    }
}


exports.create = async(req,res)=>{
    try{
        
        const user=await User.create({
             Name:req.body.Name,
             email:req.body.email,
             password:req.body.password ,
             ConfirmPassword:req.body.ConfirmPassword}
        //    StudentId:req.body.StudentId,
        //    Birthday:req.body.Birthday 

        ) 
        
           
    
        res.json({
            //  user:user 
             user //when key and value is same
        })
        // // res.send("data send successfully")
        // console.log(req.body.Name);

        // console.log("hi hansland") 
        // console.log(req.query)
        // res.send("hey robin create successful")
    }
    catch(e){
        res.send("user already exist");
    }
}

exports.getAllUsers=async(req,res)=>{
    try{
        const user =await User.find();
        res.status(200).json({user})
                                    
    }
    catch(e){
        console.log(e)
    }
} 


exports.makeAdmin=async(req,res)=>{
    try{
        const user =await User.findOne({_id:req.params.__id});
        if(user.Role=="Admin")
         {
            res.json({
                message:"Already Admin"
            })
            return;
         }
         user.Role="Admin"
        await user.save()
        // User.update({Role:"Admin"})
        res.status(200).json({user})
    }
    catch(e){
        console.log(e)
    }
}


exports.read =async(req,res)=>{
    try{
        const user = await User.findOne({email:"mk12@gmail.com"})
        if(!user){
            return res.status(404).json({
                success:false,
                message:"User not found"
            })
        }
        res.status(200).json({
            success:true,
            user
        })
        // res.send("hey robin read successful") 
    }
    catch(e){
        console.log(e)
    }
}

exports.put =async(req,res)=>{
    try{
        res.send("hey robin put successful")
    }
    catch(e){
        console.log(e)
    }
}

exports.patch =async(req,res)=>{
    try{
        res.send("hey robin patch successful")
    }
    catch(e){
        console.log(e)
    }
}

exports.Delete =async(req,res)=>{
    try{
        await User.findByIdAndDelete(req.params.__id) ;
                                    //({which id to be deleted taken from params})
        res.json({message:"Deleted"});
    }
    catch(e){
        console.log(e)
    }
}


// JWT TOKEN creation 

// exports.api1 =async(req,res)=>{
//     try{
//         const token=jwt.sign("madhav",process.env.JWT_SECRET_KEY); // token generated (encryption)
//         const verify=jwt.verify(token,process.env.JWT_SECRET_KEY); //token verify (decryption)

//          res.json({
//             message:"sign successful",
//             token,verify
//          })
//     }
//     catch(e){
//         console.log(e)
//     }
// }






